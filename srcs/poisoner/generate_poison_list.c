/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_poison_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:10:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 10:42:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

static void		allocate_data_instances(uint32_t **instances_count)
{
	uint32_t	i;

	i = 0;
	while (i < SUPPORTED_POISONS_TYPES)
	{
		if (NULL == (instances_count[i] = malloc(sizeof(uint32_t) * poisoners_count_per_type[i])))
		{
			perror("allocate_data_instances(): ");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static uint32_t		**count_data_instances(t_ofile *ofile, uint32_t **instances_count)
{
	uint32_t	i;

	i = 0;
	while (i < poisoners_count_per_type[LC_POISON])
	{
		instances_count[LC_POISON][i] = ofile_object_count_lc(ofile, poisoners[LC_POISON][i].cmd);
		i++;
	}
	if (ofile->mh)
		instances_count[LC_POISON][14] = ofile->mh->ncmds;
	else if (ofile->mh_64)
		instances_count[LC_POISON][14] = ofile->mh_64->ncmds;
	instances_count[LC_POISON][15] = instances_count[LC_POISON][14];

	bzero(instances_count[FAT_LEVEL_POISON], sizeof(uint32_t) * poisoners_count_per_type[FAT_LEVEL_POISON]);
	if (ofile->fat_header)
	{
		instances_count[FAT_LEVEL_POISON][0] = ofile->fat_header->nfat_arch;
		instances_count[FAT_LEVEL_POISON][1] = ofile->fat_header->nfat_arch;
	}
	if (ofile->fat_archs)
	{
		instances_count[FAT_LEVEL_POISON][2] = ofile->fat_header->nfat_arch;
		instances_count[FAT_LEVEL_POISON][3] = ofile->fat_header->nfat_arch;
	}
	else if (ofile->fat_archs_64)
	{
		instances_count[FAT_LEVEL_POISON][4] = ofile->fat_header->nfat_arch;
		instances_count[FAT_LEVEL_POISON][5] = ofile->fat_header->nfat_arch;
	}
	bzero(instances_count[ARCHIVE_LEVEL_POISON], sizeof(uint32_t) * poisoners_count_per_type[ARCHIVE_LEVEL_POISON]);
	if (ofile->ranlibs)
	{
		instances_count[ARCHIVE_LEVEL_POISON][0] = (uint32_t)ofile->nran;
		instances_count[ARCHIVE_LEVEL_POISON][1] = (uint32_t)ofile->nran;
	}
	else if (ofile->ranlibs_64)
	{
		instances_count[ARCHIVE_LEVEL_POISON][2] = (uint32_t)ofile->nran;
		instances_count[ARCHIVE_LEVEL_POISON][3] = (uint32_t)ofile->nran;
	}
	bzero(instances_count[SUB_LC_LEVEL_POISON], sizeof(uint32_t) * poisoners_count_per_type[SUB_LC_LEVEL_POISON]);
	instances_count[SUB_LC_LEVEL_POISON][0] = get_nsects(ofile);
	instances_count[SUB_LC_LEVEL_POISON][1] = instances_count[SUB_LC_LEVEL_POISON][0];
	instances_count[SUB_LC_LEVEL_POISON][2] = instances_count[SUB_LC_LEVEL_POISON][0];
	instances_count[SUB_LC_LEVEL_POISON][3] = instances_count[SUB_LC_LEVEL_POISON][0];

	instances_count[SUB_LC_LEVEL_POISON][4] = get_nsects_64(ofile);
	instances_count[SUB_LC_LEVEL_POISON][5] = instances_count[SUB_LC_LEVEL_POISON][4];
	instances_count[SUB_LC_LEVEL_POISON][6] = instances_count[SUB_LC_LEVEL_POISON][4];
	instances_count[SUB_LC_LEVEL_POISON][7] = instances_count[SUB_LC_LEVEL_POISON][4];

	struct symtab_command	*sc = ofile_get_symbol_table_lc(ofile);

	if (sc == NULL || ofile->mh_64 || ofile->mh == NULL)
		instances_count[SUB_LC_LEVEL_POISON][8] = 0;
	else
	{
		instances_count[SUB_LC_LEVEL_POISON][8] = sc->nsyms;
		instances_count[SUB_LC_LEVEL_POISON][13] = 0;
	}

	if (sc == NULL || ofile->mh || ofile->mh_64 == NULL)
		instances_count[SUB_LC_LEVEL_POISON][13] = 0;
	else
	{
		instances_count[SUB_LC_LEVEL_POISON][8] = 0;
		instances_count[SUB_LC_LEVEL_POISON][13] = sc->nsyms;
	}
	instances_count[SUB_LC_LEVEL_POISON][9] = instances_count[SUB_LC_LEVEL_POISON][8];
	instances_count[SUB_LC_LEVEL_POISON][10] = instances_count[SUB_LC_LEVEL_POISON][8];
	instances_count[SUB_LC_LEVEL_POISON][11] = instances_count[SUB_LC_LEVEL_POISON][8];
	instances_count[SUB_LC_LEVEL_POISON][12] = instances_count[SUB_LC_LEVEL_POISON][8];

	instances_count[SUB_LC_LEVEL_POISON][14] = instances_count[SUB_LC_LEVEL_POISON][13];
	instances_count[SUB_LC_LEVEL_POISON][15] = instances_count[SUB_LC_LEVEL_POISON][13];
	instances_count[SUB_LC_LEVEL_POISON][16] = instances_count[SUB_LC_LEVEL_POISON][13];
	instances_count[SUB_LC_LEVEL_POISON][17] = instances_count[SUB_LC_LEVEL_POISON][13];


	bzero(instances_count[MACHO_LEVEL_POISON], sizeof(uint32_t) * poisoners_count_per_type[MACHO_LEVEL_POISON]);
	if (ofile->mh)// well, doesn't mean shit in fat or archive context
	{
		instances_count[MACHO_LEVEL_POISON][0] = 1;
		instances_count[MACHO_LEVEL_POISON][1] = 1;
	}
	else if (ofile->mh_64)
	{
		instances_count[MACHO_LEVEL_POISON][2] = 1;
		instances_count[MACHO_LEVEL_POISON][3] = 1;
	}
	return (instances_count);
}


static inline int32_t			check_type_instances_to_poison(uint32_t **instances_count, t_poison_type type)
{
	uint32_t	i;

	i = 0;
	while (i < poisoners_count_per_type[type])
	{
		if (instances_count[type][i] != 0)
			return (1);
		i++;
	}
	return (0);
}

static inline int32_t			check_type_instances(uint32_t **instances_count)
{
	uint32_t	i;

	i = 0;
	while (i < SUPPORTED_POISONS_TYPES)
	{
		if (check_type_instances_to_poison(instances_count, i))
			return (1);
		i++;
	}
	return (0);
}

static inline void				free_instances_count(uint32_t **instances_count)
{
	uint32_t	i;

	i = 0;
	while (i < SUPPORTED_POISONS_TYPES)
		free(instances_count[i++]);
}

static inline t_poison_type	get_random_poison_type(t_poison_generator_config *config, uint32_t **instances_count)
{
	t_poison_type	type;

	type = (rand() % SUPPORTED_POISONS_TYPES);
	while (42)
	{
		type = (rand() % SUPPORTED_POISONS_TYPES);
		if (config->actived_poisons[type] == true
			&& check_type_instances_to_poison(instances_count, type) == 1)
			break ;
	}
	return (type);
}

t_poison_list	*generate_poison_list(t_ofile *ofile, t_poison_generator_config *config)
{
	t_poison_type	type;
	t_poison_list	*plist;
	uint32_t		*instances_count[SUPPORTED_POISONS_TYPES];
	uint64_t		alloc_size;
	uint32_t		i;

	if (!ofile || !config)
		return (NULL);
	alloc_size = sizeof(*plist) + sizeof(t_poison_command) * config->pnbr;
	if (NULL == (plist = malloc(alloc_size)))
		exit(EXIT_FAILURE);
	assert(!config->specific_plist); // not supported right now
	bzero(plist, alloc_size);
	allocate_data_instances(instances_count);
	count_data_instances(ofile, instances_count);
	plist->pnbr = config->pnbr;
	plist->poison_commands = (t_poison_command *)(void *)(plist + 1);
	if (check_type_instances(instances_count) == 0)
	{
		dprintf(2, "There is nothing to poison in this mach-o file\n");
		free_instances_count(instances_count);
		return (NULL);
	}
	i = 0;
	while (i < config->pnbr)
	{
		type = get_random_poison_type(config, instances_count);
		plist->poison_commands[i] = generate_poison_command(type, instances_count);
		i++;
	}
	free_instances_count(instances_count);
	return (plist);
}
