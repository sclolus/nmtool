/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisoner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:18:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 03:38:50 by sclolus          ###   ########.fr       */
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

const t_poisoner			*poisoners[SUPPORTED_POISONS_TYPES] = {
(const t_poisoner []){
	INIT_POISONER(segment_command, struct segment_command, nsects, LC_SEGMENT, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, segname, LC_SEGMENT, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, fileoff, LC_SEGMENT, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, filesize, LC_SEGMENT, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command, struct segment_command, cmdsize, LC_SEGMENT, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, nsects, LC_SEGMENT_64, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, segname, LC_SEGMENT_64, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, fileoff, LC_SEGMENT_64, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, filesize, LC_SEGMENT_64, exec_lc_poisoner, finder_lc),
	INIT_POISONER(segment_command_64, struct segment_command_64, cmdsize, LC_SEGMENT_64, exec_lc_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, symoff, LC_SYMTAB, exec_lc_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, nsyms, LC_SYMTAB, exec_lc_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, stroff, LC_SYMTAB, exec_lc_poisoner, finder_lc),
	INIT_POISONER(symtab_command, struct symtab_command, strsize, LC_SYMTAB, exec_lc_poisoner, finder_lc),
	INIT_POISONER(load_command, struct load_command, cmdsize, 0, exec_lc_poisoner, finder_lc),
	INIT_POISONER(load_command, struct load_command, cmd, 0, exec_lc_poisoner, finder_lc),
},
(const t_poisoner []){
	INIT_POISONER(fat_arch, struct fat_arch, offset, 0, NULL, NULL),
	INIT_POISONER(fat_arch, struct fat_arch, size, 0, NULL, NULL),
	INIT_POISONER(fat_arch_64, struct fat_arch_64, offset, 0, NULL, NULL),
	INIT_POISONER(fat_arch_64, struct fat_arch_64, size, 0, NULL, NULL),
},
(const t_poisoner []){
	INIT_POISONER(ranlib, struct ranlib, ran_un, 0, NULL, NULL),
	INIT_POISONER(ranlib, struct ranlib, ran_off, 0, NULL, NULL),
	INIT_POISONER(ranlib_64, struct ranlib_64, ran_un, 0, NULL, NULL),
	INIT_POISONER(ranlib_64, struct ranlib_64, ran_off, 0, NULL, NULL),
},
(const t_poisoner []){
	INIT_POISONER(section, struct section, sectname, 0, exec_sub_level_lc_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, segname, 0, exec_sub_level_lc_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, size, 0, exec_sub_level_lc_poisoner, finder_section_32),
	INIT_POISONER(section, struct section, offset, 0, exec_sub_level_lc_poisoner, finder_section_32),
	INIT_POISONER(section_64, struct section_64, sectname, 0, exec_sub_level_lc_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, segname, 0, exec_sub_level_lc_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, size, 0, exec_sub_level_lc_poisoner, finder_section_64),
	INIT_POISONER(section_64, struct section_64, offset, 0, exec_sub_level_lc_poisoner, finder_section_64),
	INIT_POISONER(nlist, struct nlist, n_un, 0, exec_sub_level_lc_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_type, 0, exec_sub_level_lc_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_sect, 0, exec_sub_level_lc_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_desc, 0, exec_sub_level_lc_poisoner, finder_nlist),
	INIT_POISONER(nlist, struct nlist, n_value, 0, exec_sub_level_lc_poisoner, finder_nlist),
	INIT_POISONER(nlist_64, struct nlist_64, n_un, 0, exec_sub_level_lc_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_type, 0, exec_sub_level_lc_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_sect, 0, exec_sub_level_lc_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_desc, 0, exec_sub_level_lc_poisoner, finder_nlist_64),
	INIT_POISONER(nlist_64, struct nlist_64, n_value, 0, exec_sub_level_lc_poisoner, finder_nlist_64),
},
(const t_poisoner []){
	INIT_POISONER(mach_header, struct mach_header, ncmds, 0, exec_macho_level_poisoner, NULL),
	INIT_POISONER(mach_header, struct mach_header, sizeofcmds, 0, exec_macho_level_poisoner, NULL),
	INIT_POISONER(mach_header_64, struct mach_header_64, ncmds, 0, exec_macho_level_poisoner, NULL),
	INIT_POISONER(mach_header_64, struct mach_header_64, sizeofcmds, 0, exec_macho_level_poisoner, NULL),
},
};

/*
** It xis such a shame that type tab[some_value][] can't exists in c.
** Because the following table could have been defined by sizeof(ptr) / sizeof(*ptr)
** If you know a work around, please let me know
*/

const uint64_t	poisoners_count_per_type[SUPPORTED_POISONS_TYPES] = {
	16,
	4,
	4,
	18,
	4,
};

void			*poisoned_zone_vm_addr = NULL;

static void	exec_poisoners(t_ofile *ofile, t_poison_list *plist)
{
	t_f_poison_executor	executor;
	uint32_t			i;

	i = 0;
	while (i < plist->pnbr)
	{
		executor = poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].executor;
		if (executor)
			executor(ofile, poisoners[plist->poison_commands[i].type] + plist->poison_commands[i].pindex, plist->poison_commands + i);
		else
			dprintf(2, "Executor not implemented for %s\n", poisoners[plist->poison_commands[i].type][plist->poison_commands[i].pindex].member_name);
		i++;
	}
}

void	 poison(t_ofile *ofile, t_poison_list *plist)
{
	uint32_t			i;
	struct load_command	*lc;

	i = 0;
	assert(ofile->mh_64 && ofile->load_commands);
	lc = ofile->load_commands;
	if (ofile->ofile_type == OFILE_MACHO)
		exec_poisoners(ofile, plist);
}
