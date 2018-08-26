/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_handle_fat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:24:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/26 14:38:24 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"
#include <mach-o/arch.h>

static int32_t	otool_current_arch(t_ofile *ofile)
{
	if (ofile->arch_ofile_type == OFILE_MACHO)
	{
		return (otool_process_obj(ofile));
	}
	else if (ofile->arch_ofile_type == OFILE_FAT)
		return (otool_handle_fat(ofile));
	else if (ofile->arch_ofile_type == OFILE_ARCHIVE)
	{
		ft_printf("Archive : %s\n", ofile->file_name);
		return (otool_handle_archive(ofile));
	}
	return (-1);
}

static int32_t	otool_process_every_arch(t_ofile *ofile)
{
	uint32_t			i;

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
		if (-1 == otool_current_arch(ofile))
			return (-1);
		i++;
	}
	return (0);
}

int32_t			otool_handle_fat(t_ofile *ofile)
{
	int32_t				narch_for_arch;
	const NXArchInfo	*host_arch;

	assert((host_arch = NXGetLocalArchInfo()));
	if (-1 == (narch_for_arch = ofile_fat_find_arch(ofile,
		host_arch->cputype | CPU_ARCH_ABI64, host_arch->cpusubtype)))
		return (otool_process_every_arch(ofile));
	else
	{
		if (-1 == ofile_load_narch(ofile, (uint32_t)narch_for_arch))
			return (-1);
		if (ofile->arch_ofile_type != OFILE_ARCHIVE)
			ft_printf("%s:\n", ofile->file_name);
		return (otool_current_arch(ofile));
	}
}
