/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_handle_fat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 11:46:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 12:31:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"
#include <mach-o/arch.h>

int32_t			nm_current_arch(t_ofile *ofile, t_nm_flags *flags)
{
	if (ofile->arch_ofile_type == OFILE_MACHO)
		return (nm_process_obj(ofile, flags));
	else if (ofile->arch_ofile_type == OFILE_FAT)
		return (nm_handle_fat(ofile, flags));
	else if (ofile->arch_ofile_type == OFILE_ARCHIVE)
		return (nm_handle_archive(ofile, flags));
	return (-1);
}

static int32_t	fat_process_all_archs(t_ofile *ofile, t_nm_flags *flags)
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
			ft_printf("\n%s (for architecture %s):\n", ofile->file_name,
				get_cputype_name(ofile->fat_archs ? ofile->fat_archs[i].cputype
									: ofile->fat_archs_64[i].cputype));
		else
			ft_printf("%s:\n", ofile->file_name);
		if (-1 == nm_current_arch(ofile, flags))
			return (-1);
		i++;
	}
	return (0);
}

int32_t			nm_handle_fat(t_ofile *ofile, t_nm_flags *flags)
{
	int32_t				narch_for_arch;
	const NXArchInfo	*host_arch;

	host_arch = NXGetLocalArchInfo();
	if (-1 == (narch_for_arch = ofile_fat_find_arch(ofile,
		host_arch->cputype | CPU_ARCH_ABI64, host_arch->cpusubtype)))
		return (fat_process_all_archs(ofile, flags));
	else
	{
		if (-1 == ofile_load_narch(ofile, (uint32_t)narch_for_arch))
			return (-1);
		return (nm_current_arch(ofile, flags));
	}
}