/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_fat_find_arch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 05:41:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 11:21:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	ofile_fat_find_arch(t_ofile *ofile,
							cpu_type_t cputype,
							cpu_subtype_t subtype)
{
	uint32_t	i;

	assert(ofile->fat_header && (ofile->fat_archs || ofile->fat_archs_64));
	i = 0;
	(void)subtype;
	while (i < ofile->fat_header->nfat_arch)
	{
		if (-1 == ofile_file_check_addr_size(ofile,
	(ofile->fat_archs ? (void *)ofile->fat_archs : (void *)ofile->fat_archs_64),
	sizeof(struct fat_arch_64)))
			return (-1);
		if (ofile->fat_archs && ofile->fat_archs[i].cputype == cputype /* && ofile->fat_archs[i].cpusubtype == subtype */)
			return ((int32_t)i);
		else if (ofile->fat_archs_64 && ofile->fat_archs_64[i].cputype /* == cputype && ofile->fat_archs_64[i].cpusubtype == subtype */)
			return ((int32_t)i);
		i++;
	}
	return (-1);
}
