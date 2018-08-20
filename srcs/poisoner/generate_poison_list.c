/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_poison_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:10:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 07:31:19 by sclolus          ###   ########.fr       */
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
		printf("instances_count[LC_POISON][%u] = %u\n", i, instances_count[LC_POISON][i]);
		i++;
	}
	bzero(instances_count[FAT_LEVEL_POISON], sizeof(uint32_t) * poisoners_count_per_type[FAT_LEVEL_POISON]);
	if (ofile->fat_archs)
	{
		instances_count[FAT_LEVEL_POISON][0] = ofile->fat_header->nfat_arch;
		instances_count[FAT_LEVEL_POISON][1] = ofile->fat_header->nfat_arch;
	}
	else if (ofile->fat_archs_64)
	{
		instances_count[FAT_LEVEL_POISON][2] = ofile->fat_header->nfat_arch;
		instances_count[FAT_LEVEL_POISON][3] = ofile->fat_header->nfat_arch;
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

t_poison_list	*generate_poison_list(t_ofile *ofile, uint32_t pnbr)
{
	t_poison_list	*plist;
	uint32_t		*instances_count[SUPPORTED_POISONS_TYPES];
	uint64_t		alloc_size;
	uint32_t		i;

	alloc_size = sizeof(*plist) + sizeof(t_poison_command) * pnbr;
	if (NULL == (plist = malloc(alloc_size)))
		exit(EXIT_FAILURE);
	bzero(plist, alloc_size);
	allocate_data_instances(instances_count);
	count_data_instances(ofile, instances_count);
	plist->pnbr = pnbr;
	plist->poison_commands = (t_poison_command *)(void *)(plist + 1);
	i = 0;
	while (i < pnbr)
	{
		plist->poison_commands[i] = generate_poison_command((rand() % 2) == 0 ? LC_POISON : MACHO_LEVEL_POISON, instances_count);
		i++;
	}
	i = 0;
	while (i < SUPPORTED_POISONS_TYPES)
		free(instances_count[i++]);
	return (plist);
}
