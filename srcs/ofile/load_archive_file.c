/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_archive_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 02:11:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:20:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static inline bool		is_symdef_32(const t_ofile *ofile)
{
	return (ft_strncmp((const char *)ofile->archive_member_header.member_name,
		SYMDEF, sizeof(SYMDEF))
		|| ft_strncmp((const char *)ofile->archive_member_header.member_name,
		SYMDEF_SORTED, sizeof(SYMDEF_SORTED)));
}

static inline bool		is_symdef_64(const t_ofile *ofile)
{
	return (ft_strncmp((const char *)ofile->archive_member_header.member_name,
			SYMDEF_64, sizeof(SYMDEF_64))
			|| ft_strncmp((const char *)ofile->archive_member_header.member_name,
			SYMDEF_64_SORTED, sizeof(SYMDEF_64_SORTED)));
}

static inline int32_t	set_archive_symdef(t_ofile *ofile)
{
	ofile->symdef_addr = ofile->archive_member_header_addr;
	if (is_symdef_32(ofile))
	{
		ofile->ranlibs = ofile_archive_get_member_starting_addr(ofile);
		ofile->nran = *(uint32_t*)(void *)ofile->ranlibs / sizeof(struct ranlib);
		ofile->ranlibs = (void *)((uint8_t*)ofile->ranlibs + 4);
		ofile->string_table_size = (uint64_t)*(uint32_t *)(void *)((uint8_t *)ofile->ranlibs + ofile->nran * sizeof(struct ranlib));
		ofile->string_table = (char *)((uint8_t *)ofile->ranlibs + ofile->nran * sizeof(struct ranlib) + sizeof(uint32_t));
		ofile->nmembers = ofile_get_nmembers(ofile);
	}
	else if (is_symdef_64(ofile))
	{
		ofile->ranlibs_64 = ofile_archive_get_member_starting_addr(ofile);
		ofile->nran = *(uint64_t*)(void *)ofile->ranlibs_64 / sizeof(struct ranlib_64);
		ofile->ranlibs_64 = (void *)((uint8_t*)ofile->ranlibs + 8);
		ofile->string_table_size = *(uint64_t *)(void *)((uint8_t *)ofile->ranlibs_64 + ofile->nran * sizeof(struct ranlib_64));
		ofile->string_table = (char *)((uint8_t *)ofile->ranlibs_64 + ofile->nran * sizeof(struct ranlib_64) + sizeof(uint64_t));
		ofile->nmembers = ofile_get_nmembers(ofile);
	}
	else
	{
		ft_dprintf(2, "First member of archive file is not SYMDEF or SYMDEF_SORTED\n");
		return (-1);
	}
	return (0);
}

int32_t	load_archive_file(t_ofile *ofile)
{
	ofile->archive_start_addr = ofile->vm_addr;
	ofile->archive_member_header_addr = (void *)((uint8_t*)ofile->archive_start_addr + sizeof(STATIC_LIB_MAGIC) - 1);
	ofile->symdef_addr = NULL;
	ofile->members = NULL;
	ofile->ranlibs = NULL;
	ofile->ranlibs_64 = NULL;
	if (-1 == archive_parse_member_header(ofile))
		return (-1);
	ofile->members = ofile->archive_member_header_addr;
	if (-1 == set_archive_symdef(ofile))
		return (-1);
	return (0);
}
