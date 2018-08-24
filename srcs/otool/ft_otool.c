/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:51:15 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 07:19:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <mach-o/arch.h>

static inline int32_t	otool_process_obj(t_ofile *ofile)
{
	t_otool_info	otool_info;
	int32_t			ret;

	init_otool_info(ofile, &otool_info);
	assert(otool_info.secs || otool_info.secs_64);
	if (otool_info.text_nsec == NO_SECT_FOUND)
	{
		ft_dprintf(2, "There is no text section in the mach-o file\n");
		cleanup_otool_info(&otool_info);
		return (-1);
	}
	if (otool_info.secs)
	{
		ret = otool_print_section(ofile, &otool_info, otool_info.text_nsec);
		cleanup_otool_info(&otool_info);
		if (ret == -1)
		{
			ft_dprintf(2, "Truncated or malformed object file (the text section would go past the end of the file)\n");
			return (-1);
		}
		return (0);
	}
	else
	{
		ret = otool_print_section_64(ofile, &otool_info, otool_info.text_nsec);
		cleanup_otool_info(&otool_info);
		if (ret == -1)
		{
			ft_dprintf(2, "Truncated or malformed object file (the text section would go past the end of the file)\n");
			return (-1);
		}
		return (0);
	}
}

static int32_t otool_handle_fat(t_ofile *ofile)
{
	int32_t				narch_for_arch;
	uint32_t			i;
	const NXArchInfo	*host_arch;


	assert((host_arch = NXGetLocalArchInfo()));
	if (-1 == (narch_for_arch = ofile_fat_find_arch(ofile,
		host_arch->cputype | CPU_ARCH_ABI64, host_arch->cpusubtype)))
	{
		i = 0;
		while (i < ofile->fat_header->nfat_arch)
		{
			if (-1 == ofile_load_narch(ofile, i))
			{
				i++;
				continue ;
			}
			if (ofile->fat_header->nfat_arch != 1)
				ft_printf("%s (architecture %s):\n", ofile->file_name,
				   get_cputype_name(ofile->fat_archs ? ofile->fat_archs[i].cputype
									: ofile->fat_archs_64[i].cputype));
			else
				ft_printf("%s:\n", ofile->file_name);
			if (-1 == otool_process_obj(ofile))
				return (-1);
			i++;
		}
	}
	else
	{
		ft_printf("%s:\n", ofile->file_name);
		if (-1 == ofile_load_narch(ofile, (uint32_t)narch_for_arch))
			return (-1);
		return (otool_process_obj(ofile));
	}
	return (0);
}

static int32_t	otool_handle_archive(t_ofile *ofile)
{
	uint64_t		i;

	i = 0;
	while (i < ofile->nmembers)
	{
		if (-1 == ofile_load_narchive_member(ofile, i))
		{
			i++;
			continue ;
		}
		ft_printf("%s(%s):\n", ofile->file_name
			   , ofile->archive_member_header.member_name);
		if (-1 == otool_process_obj(ofile))
			return (-1);
		i++;
	}
	return (0);
}

int32_t	otool(t_ofile *ofile)
{
	if (ofile->ofile_type == OFILE_MACHO)
	{
		ft_printf("%s:\n", ofile->file_name);
		return (otool_process_obj(ofile));
	}
	else if (ofile->ofile_type == OFILE_FAT)
	{
		return (otool_handle_fat(ofile));
	}
	else if (ofile->ofile_type == OFILE_ARCHIVE)
	{
		ft_printf("Archive : %s\n", ofile->file_name);
		return (otool_handle_archive(ofile));
	}
	return (-1);

}
