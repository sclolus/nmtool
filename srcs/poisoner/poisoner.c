/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisoner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:18:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:20:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

DEFINE_GETTER(segment_command, struct segment_command, nsects)
DEFINE_GETTER(segment_command, struct segment_command, segname)
DEFINE_GETTER(segment_command, struct segment_command, fileoff)
DEFINE_GETTER(segment_command, struct segment_command, filesize)
DEFINE_GETTER(segment_command, struct segment_command, cmdsize)

DEFINE_GETTER(segment_command_64, struct segment_command_64, nsects)
DEFINE_GETTER(segment_command_64, struct segment_command_64, segname)
DEFINE_GETTER(segment_command_64, struct segment_command_64, fileoff)
DEFINE_GETTER(segment_command_64, struct segment_command_64, filesize)
DEFINE_GETTER(segment_command_64, struct segment_command_64, cmdsize)

DEFINE_GETTER(section, struct section, sectname)
DEFINE_GETTER(section, struct section, segname)
DEFINE_GETTER(section, struct section, size)
DEFINE_GETTER(section, struct section, offset)

DEFINE_GETTER(section_64, struct section_64, sectname)
DEFINE_GETTER(section_64, struct section_64, segname)
DEFINE_GETTER(section_64, struct section_64, size)
DEFINE_GETTER(section_64, struct section_64, offset)

DEFINE_GETTER(symtab_command, struct symtab_command, symoff)
DEFINE_GETTER(symtab_command, struct symtab_command, nsyms)
DEFINE_GETTER(symtab_command, struct symtab_command, stroff)
DEFINE_GETTER(symtab_command, struct symtab_command, strsize)

DEFINE_GETTER(mach_header, struct mach_header, ncmds)
DEFINE_GETTER(mach_header, struct mach_header, sizeofcmds)

DEFINE_GETTER(mach_header_64, struct mach_header_64, ncmds)
DEFINE_GETTER(mach_header_64, struct mach_header_64, sizeofcmds)

DEFINE_GETTER(fat_arch, struct fat_arch, offset)
DEFINE_GETTER(fat_arch, struct fat_arch, size)

DEFINE_GETTER(fat_arch_64, struct fat_arch_64, offset)
DEFINE_GETTER(fat_arch_64, struct fat_arch_64, size)

DEFINE_GETTER(nlist, struct nlist, n_un)
DEFINE_GETTER(nlist, struct nlist, n_type)
DEFINE_GETTER(nlist, struct nlist, n_sect)
DEFINE_GETTER(nlist, struct nlist, n_desc)
DEFINE_GETTER(nlist, struct nlist, n_value)

DEFINE_GETTER(nlist_64, struct nlist_64, n_un)
DEFINE_GETTER(nlist_64, struct nlist_64, n_type)
DEFINE_GETTER(nlist_64, struct nlist_64, n_sect)
DEFINE_GETTER(nlist_64, struct nlist_64, n_desc)
DEFINE_GETTER(nlist_64, struct nlist_64, n_value)

DEFINE_GETTER(ranlib, struct ranlib, ran_un)
DEFINE_GETTER(ranlib, struct ranlib, ran_off)

DEFINE_GETTER(ranlib_64, struct ranlib_64, ran_un)
DEFINE_GETTER(ranlib_64, struct ranlib_64, ran_off)

DEFINE_GETTER(load_command, struct load_command, cmdsize)
DEFINE_GETTER(load_command, struct load_command, cmd)


DEFINE_SETTER(load_command, struct load_command, cmdsize)
DEFINE_SETTER(load_command, struct load_command, cmd)
DEFINE_SETTER(segment_command, struct segment_command, nsects)
DEFINE_SETTER(segment_command, struct segment_command, segname)
DEFINE_SETTER(segment_command, struct segment_command, fileoff)
DEFINE_SETTER(segment_command, struct segment_command, filesize)
DEFINE_SETTER(segment_command, struct segment_command, cmdsize)

DEFINE_SETTER(segment_command_64, struct segment_command_64, nsects)
DEFINE_SETTER(segment_command_64, struct segment_command_64, segname)
DEFINE_SETTER(segment_command_64, struct segment_command_64, fileoff)
DEFINE_SETTER(segment_command_64, struct segment_command_64, filesize)
DEFINE_SETTER(segment_command_64, struct segment_command_64, cmdsize)

DEFINE_SETTER(section, struct section, sectname)
DEFINE_SETTER(section, struct section, segname)
DEFINE_SETTER(section, struct section, size)
DEFINE_SETTER(section, struct section, offset)

DEFINE_SETTER(section_64, struct section_64, sectname)
DEFINE_SETTER(section_64, struct section_64, segname)
DEFINE_SETTER(section_64, struct section_64, size)
DEFINE_SETTER(section_64, struct section_64, offset)

DEFINE_SETTER(symtab_command, struct symtab_command, symoff)
DEFINE_SETTER(symtab_command, struct symtab_command, nsyms)
DEFINE_SETTER(symtab_command, struct symtab_command, stroff)
DEFINE_SETTER(symtab_command, struct symtab_command, strsize)

DEFINE_SETTER(mach_header, struct mach_header, ncmds)
DEFINE_SETTER(mach_header, struct mach_header, sizeofcmds)

DEFINE_SETTER(mach_header_64, struct mach_header_64, ncmds)
DEFINE_SETTER(mach_header_64, struct mach_header_64, sizeofcmds)

DEFINE_SETTER(fat_arch, struct fat_arch, offset)
DEFINE_SETTER(fat_arch, struct fat_arch, size)

DEFINE_SETTER(fat_arch_64, struct fat_arch_64, offset)
DEFINE_SETTER(fat_arch_64, struct fat_arch_64, size)

DEFINE_SETTER(nlist, struct nlist, n_un)
DEFINE_SETTER(nlist, struct nlist, n_type)
DEFINE_SETTER(nlist, struct nlist, n_sect)
DEFINE_SETTER(nlist, struct nlist, n_desc)
DEFINE_SETTER(nlist, struct nlist, n_value)

DEFINE_SETTER(nlist_64, struct nlist_64, n_un)
DEFINE_SETTER(nlist_64, struct nlist_64, n_type)
DEFINE_SETTER(nlist_64, struct nlist_64, n_sect)
DEFINE_SETTER(nlist_64, struct nlist_64, n_desc)
DEFINE_SETTER(nlist_64, struct nlist_64, n_value)

DEFINE_SETTER(ranlib, struct ranlib, ran_un)
DEFINE_SETTER(ranlib, struct ranlib, ran_off)

DEFINE_SETTER(ranlib_64, struct ranlib_64, ran_un)
DEFINE_SETTER(ranlib_64, struct ranlib_64, ran_off)

DEFINE_GETTER(fat_header, struct fat_header, magic)
DEFINE_GETTER(fat_header, struct fat_header, nfat_arch)

DEFINE_SETTER(fat_header, struct fat_header, magic)
DEFINE_SETTER(fat_header, struct fat_header, nfat_arch)

const t_poisoner			*poisoners[SUPPORTED_POISONS_TYPES] = {
(const t_poisoner []){
	INIT_POISONER(segment_command, struct segment_command, nsects, LC_SEGMENT, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, segname, LC_SEGMENT, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, fileoff, LC_SEGMENT, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, filesize, LC_SEGMENT, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, cmdsize, LC_SEGMENT, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, nsects, LC_SEGMENT_64, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, segname, LC_SEGMENT_64, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, fileoff, LC_SEGMENT_64, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, filesize, LC_SEGMENT_64, exec_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, cmdsize, LC_SEGMENT_64, exec_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, symoff, LC_SYMTAB, exec_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, nsyms, LC_SYMTAB, exec_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, stroff, LC_SYMTAB, exec_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, strsize, LC_SYMTAB, exec_poisoner, finder_lc),
	INIT_POISONER(load_command, struct load_command, cmdsize, 0, exec_poisoner, finder_lc),
	INIT_POISONER(load_command, struct load_command, cmd, 0, exec_poisoner, finder_lc),
},
(const t_poisoner []){
	INIT_POISONER(fat_header, struct fat_header, magic, 0, exec_poisoner, finder_fat_header),
	INIT_POISONER(fat_header, struct fat_header, nfat_arch, 0, exec_poisoner, finder_fat_header),
	INIT_POISONER(fat_arch, struct fat_arch, offset, 0, exec_poisoner, finder_fat_arch),
	INIT_POISONER(fat_arch, struct fat_arch, size, 0, exec_poisoner, finder_fat_arch),
	INIT_POISONER(fat_arch_64, struct fat_arch_64, offset, 0, exec_poisoner, finder_fat_arch_64),
	INIT_POISONER(fat_arch_64, struct fat_arch_64, size, 0, exec_poisoner, finder_fat_arch_64),
},
(const t_poisoner []){
	INIT_POISONER(ranlib, struct ranlib, ran_un, 0, exec_poisoner, finder_ranlib),
	INIT_POISONER(ranlib, struct ranlib, ran_off, 0, exec_poisoner, finder_ranlib),
	INIT_POISONER(ranlib_64, struct ranlib_64, ran_un, 0, exec_poisoner, finder_ranlib_64),
	INIT_POISONER(ranlib_64, struct ranlib_64, ran_off, 0, exec_poisoner, finder_ranlib_64),
},
(const t_poisoner []){
	INIT_POISONER(section, struct section, sectname, 0, exec_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, segname, 0, exec_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, size, 0, exec_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, offset, 0, exec_poisoner, finder_section_32),
	INIT_POISONER(section_64, struct section_64, sectname, 0, exec_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, segname, 0, exec_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, size, 0, exec_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, offset, 0, exec_poisoner, finder_section_64),
	INIT_POISONER(nlist, struct nlist, n_un, 0, exec_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_type, 0, exec_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_sect, 0, exec_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_desc, 0, exec_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_value, 0, exec_poisoner, finder_nlist),
	INIT_POISONER(nlist_64, struct nlist_64, n_un, 0, exec_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_type, 0, exec_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_sect, 0, exec_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_desc, 0, exec_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_value, 0, exec_poisoner, finder_nlist_64),
},
(const t_poisoner []){
	INIT_POISONER(mach_header, struct mach_header, ncmds, 0, exec_poisoner, finder_mach_header),
	INIT_POISONER(mach_header, struct mach_header, sizeofcmds, 0, exec_poisoner, finder_mach_header),
	INIT_POISONER(mach_header_64, struct mach_header_64, ncmds, 0, exec_poisoner, finder_mach_header_64),
	INIT_POISONER(mach_header_64, struct mach_header_64, sizeofcmds, 0, exec_poisoner, finder_mach_header_64),
},
};

/*
** It is such a shame that types like tab[some_value][] can't exists in c.
** Because the following table could have been defined by sizeof(ptr) / sizeof(*ptr)
** If you know a work around, please let me know
*/

const uint64_t	poisoners_count_per_type[SUPPORTED_POISONS_TYPES] = {
	16,
	6,
	4,
	18,
	4,
};

void			*poisoned_zone_vm_addr = NULL;

static void	exec_poisoners(t_ofile *ofile, t_poison_list *plist)
{
	t_f_poison_executor	executor;
	void				*addr;
	uint32_t			i;

	i = 0;
	while (i < plist->pnbr)
	{
		executor = poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].executor;
		if (executor)
		{
			addr = executor(ofile, poisoners[plist->poison_commands[i].type] + plist->poison_commands[i].pindex, plist->poison_commands + i);
			if (plist->poison_commands[i].action == POISON_ACTION_TRUNCATE && plist->truncation_addr < addr)
				plist->truncation_addr = addr;
		}
		else
			ft_dprintf(2, "Executor not implemented for %s\n", poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].member_name);
		i++;
	}
}

static void	exec_poisoners_by_predicate(t_ofile *ofile,
										t_poison_list *plist,
										bool (*predicate)(t_poison_command *cmd))
{
	t_f_poison_executor	executor;
	uint32_t			i;

	i = 0;
	while (i < plist->pnbr)
	{
		if (predicate(&plist->poison_commands[i]))
		{
			executor = poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].executor;
			if (executor)
				executor(ofile, poisoners[plist->poison_commands[i].type] + plist->poison_commands[i].pindex, plist->poison_commands + i);
			else
				ft_dprintf(2, "Executor not implemented for %s\n", poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].member_name);
		}
		i++;
	}
}

static int32_t			find_current_host_narch(t_ofile *ofile)
{
	const NXArchInfo	*host_arch;

	assert((host_arch = NXGetLocalArchInfo()));
	return (ofile_fat_find_arch(ofile,
				host_arch->cputype | CPU_ARCH_ABI64, host_arch->cpusubtype));
}

static t_poison_list	*handle_fat_file(t_ofile *ofile, t_poison_generator_config *config)
{
	t_poison_list	*plist;
	uint32_t		i;
	int32_t			narch_for_arch;
	uint32_t		pnbr_for_fat_level;


	pnbr_for_fat_level = (uint32_t)rand() % (config->pnbr + 1);
	assert(ofile->fat_header && (ofile->fat_archs || ofile->fat_archs_64));
	assert(plist = generate_poison_list(ofile,
										&(t_gen_config){NULL, pnbr_for_fat_level,
											{false, true, false, false, false},
												config->poison_every_archs, config->truncate, {0}}));
	exec_poisoners(ofile, plist);
	if (pnbr_for_fat_level == config->pnbr)
		return (plist);
	free_poison_list(plist);
	config->pnbr -= pnbr_for_fat_level;
	config->actived_poisons[FAT_LEVEL_POISON] = false;

	plist = NULL;
	if (-1 == (narch_for_arch = find_current_host_narch(ofile))
		|| config->poison_every_archs)
	{
		i = 0;
		while (i < ofile->fat_header->nfat_arch)
		{
			free_poison_list(plist);
			if (-1 == ofile_load_narch(ofile, i))
			{
				ft_dprintf(2, "Failed to parse fat file, aborting the poisoning...\n");
				return (NULL);
			}
			assert(plist = generate_poison_list(ofile, config));
			exec_poisoners(ofile, plist); // let's just do that for now
			i++;
		}
	}

	assert(plist = generate_poison_list(ofile, config));
	if (-1 == ofile_load_narch(ofile, (uint32_t)narch_for_arch))
	{
		ft_dprintf(2, "Failed to parse fat file, aborting the poisoning...\n");
		free_poison_list(plist);
		return (NULL);
	}
	exec_poisoners(ofile, plist); // let's just do that for now
	return (plist);
}

static t_poison_list	*handle_archive_file(t_ofile *ofile, t_gen_config *config)
{
	t_poison_list	*plist;
	uint64_t		i;
	uint32_t		pnbr_for_fat_level;

	pnbr_for_fat_level = (uint32_t)rand() % (config->pnbr + 1);
	assert(ofile->archive_start_addr && ofile->symdef_addr);
	assert(plist = generate_poison_list(ofile,
										&(t_gen_config){NULL, pnbr_for_fat_level,
											{false, false, true, false, false},
											config->poison_every_archs, config->truncate, {0}}));
	exec_poisoners(ofile, plist);
	if (pnbr_for_fat_level == config->pnbr)
		return (plist);
	free_poison_list(plist);
	config->pnbr -= pnbr_for_fat_level;
	config->actived_poisons[FAT_LEVEL_POISON] = false;
	config->actived_poisons[ARCHIVE_LEVEL_POISON] = false;
	plist = NULL;
	i = 0;
	while (i < ofile->nmembers)
	{
		free_poison_list(plist);
		if (-1 == ofile_load_narchive_member(ofile, i))
		{
			ft_dprintf(2, "Failed to parse archive file, aborting the poisoning\n");
			return (NULL);
		}
		assert(plist = generate_poison_list(ofile, config));
		exec_poisoners(ofile, plist);
		i++;
	}
	return (plist);
}

t_poison_list			*poison(t_ofile *ofile, t_gen_config *config)
{
	t_poison_list		*plist;

	(void)exec_poisoners_by_predicate;
	if (config->pnbr == 0)
		return (NULL);
	plist = NULL;
	if (ofile->ofile_type == OFILE_MACHO)
	{
		assert(plist = generate_poison_list(ofile, config));
		exec_poisoners(ofile, plist);
	}
	else if (ofile->ofile_type == OFILE_FAT)
		return (handle_fat_file(ofile, config));
	else if (ofile->ofile_type == OFILE_ARCHIVE)
		return (handle_archive_file(ofile, config));
	return (plist);
}
