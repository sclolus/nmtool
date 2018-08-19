/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 09:20:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <mach-o/arch.h>

static int32_t	nm_process_obj(t_ofile *ofile, t_nm_flags *flags)
{
	t_nm_process_info	nm_info;
	uint32_t			i;
	t_symbol			*symbols;

	if (-1 == init_nm_process_info(ofile, &nm_info))
		exit(EXIT_FAILURE);
	symbols = nm_get_symbols(&nm_info);
	nm_sort_symbols(symbols, nm_info.st_lc->nsyms, flags);
	i = 0;
	while (i < nm_info.st_lc->nsyms)
	{
		if (symbols[i].len)
			nm_print_symbol(symbols + i, &nm_info, flags);
		i++;
	}
//	bzero(ofile->vm_addr, ofile->file_size); wtf
	return (0);
}

static int32_t nm_handle_fat(t_ofile *ofile, t_nm_flags *flags)
{
	int32_t				narch_for_arch;
	uint32_t			i;
	const NXArchInfo	*host_arch;


	assert((host_arch = NXGetLocalArchInfo()));
	if (-1 == (narch_for_arch = ofile_fat_find_arch(ofile, host_arch->cputype | CPU_ARCH_ABI64, host_arch->cpusubtype)))
	{
		i = 0;
		while (i < ofile->fat_header->nfat_arch)
		{
			ofile_load_narch(ofile, i);
			printf("%s: (for architecture %s)\n", ofile->file_name,
				   get_cputype_name(ofile->fat_archs ? ofile->fat_archs[i].cputype
									: ofile->fat_archs_64[i].cputype));
			if (-1 == nm_process_obj(ofile, flags))
				return (-1);
			i++;
		}
	}
	else
	{
		assert(ofile_load_narch(ofile, (uint32_t)narch_for_arch) == 0);
		return (nm_process_obj(ofile, flags));
	}
	return (0);
}

static int32_t	nm_handle_archive(t_ofile *ofile, t_nm_flags *flags)
{
	uint64_t		i;

	i = 0;
	while (i < ofile->nran)
	{
		assert(ofile_load_narchive_member(ofile, i) == 0);
		printf("\n%s(%s):\n", ofile->file_name
			   , ofile->archive_member_header.member_name);
		if (-1 == nm_process_obj(ofile, flags))
			return (-1);
		i++;
	}
	return (0);
}

int32_t	nm(t_ofile *ofile, t_nm_flags *flags)
{
	if (ofile->ofile_type == OFILE_MACHO)
		return (nm_process_obj(ofile, flags));
	else if (ofile->ofile_type == OFILE_FAT)
		return (nm_handle_fat(ofile, flags));
	else if (ofile->ofile_type == OFILE_ARCHIVE)
		return (nm_handle_archive(ofile, flags));
	return (-1);
}
