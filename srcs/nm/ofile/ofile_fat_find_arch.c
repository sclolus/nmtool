/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_fat_find_arch.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 05:41:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 06:41:13 by sclolus          ###   ########.fr       */
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
		/* printf("expected cpu: %u, sub: %u\n", cputype, subtype); */
		/* printf("%s, %u:%u\n", get_cputype_name(ofile->fat_archs[i].cputype), ofile->fat_archs[i].cputype, ofile->fat_archs[i].cpusubtype); */
		if (ofile->fat_archs && ofile->fat_archs[i].cputype == cputype /* && ofile->fat_archs[i].cpusubtype == subtype */)
			return ((int32_t)i);
		else if (ofile->fat_archs_64 && ofile->fat_archs_64[i].cputype /* == cputype && ofile->fat_archs_64[i].cpusubtype == subtype */)
			return ((int32_t)i);
		i++;
	}
	return (-1);
}
