/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_swap_fat_hdrs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 23:09:12 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 23:05:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

inline static void	swap_fat_hdr(struct fat_header *fat_hdr)
{
	fat_hdr->magic = swap_int32(fat_hdr->magic);
	fat_hdr->nfat_arch = swap_int32(fat_hdr->nfat_arch);
}

inline static void	swap_fat_archs_hdr(t_ofile *ofile, uint32_t narch)
{
	assert(ofile->fat_archs || ofile->fat_archs_64);
	assert(sizeof(ofile->fat_archs->cputype) == sizeof(int32_t));
	assert(sizeof(ofile->fat_archs->cpusubtype) == sizeof(int32_t));
	if (ofile->fat_archs)
	{
		ofile->fat_archs[narch].cputype = (cpu_type_t)swap_int32((uint32_t)ofile->fat_archs[narch].cputype);
		ofile->fat_archs[narch].cpusubtype = (cpu_subtype_t)swap_int32((uint32_t)ofile->fat_archs[narch].cpusubtype);
		ofile->fat_archs[narch].offset = swap_int32(ofile->fat_archs[narch].offset);
		ofile->fat_archs[narch].size = swap_int32(ofile->fat_archs[narch].size);
		ofile->fat_archs[narch].align = swap_int32(ofile->fat_archs[narch].align);
	}
	else
	{
		ofile->fat_archs_64[narch].cputype = (cpu_type_t)swap_int32((uint32_t)ofile->fat_archs_64[narch].cputype);
		ofile->fat_archs_64[narch].cpusubtype = (cpu_subtype_t)swap_int32((uint32_t)ofile->fat_archs_64[narch].cpusubtype);
		ofile->fat_archs_64[narch].offset = swap_int64(ofile->fat_archs_64[narch].offset);
		ofile->fat_archs_64[narch].size = swap_int64(ofile->fat_archs_64[narch].size);
		ofile->fat_archs_64[narch].align = swap_int32(ofile->fat_archs_64[narch].align);
		ofile->fat_archs_64[narch].reserved = swap_int32(ofile->fat_archs_64[narch].reserved);
	}
}

void				ofile_swap_fat_hdrs(t_ofile *ofile)
{
	uint32_t	i;

	assert(ofile->fat_header);
	assert(ofile->fat_archs || ofile->fat_archs_64);
	swap_fat_hdr(ofile->fat_header);
	i = 0;
	while (i < ofile->fat_header->nfat_arch)
	{
		swap_fat_archs_hdr(ofile, i);
		i++;
	}
}
