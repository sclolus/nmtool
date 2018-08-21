/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_fat_ofile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:55:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 07:12:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static void	print_archs_names(t_ofile *ofile)
{
	uint32_t	i;

	i = 0;
	while (i < ofile->fat_header->nfat_arch)
	{
		if (ofile->fat_archs)
			printf("Arch %i: %s:%d\n", i, get_cputype_name(ofile->fat_archs[i].cputype), ofile->fat_archs[i].cpusubtype);
		else
			printf("Arch %i: %s:%d\n", i, get_cputype_name(ofile->fat_archs_64[i].cputype), ofile->fat_archs_64[i].cpusubtype);
		i++;
	}
}

int32_t	load_fat_ofile(t_ofile *ofile)
{
	assert(ofile->vm_addr);
	assert(((struct fat_header *)ofile->vm_addr)->magic == FAT_MAGIC
		   || ((struct fat_header *)ofile->vm_addr)->magic == FAT_MAGIC_64
		   || ((struct fat_header *)ofile->vm_addr)->magic == FAT_CIGAM
		   || ((struct fat_header *)ofile->vm_addr)->magic == FAT_CIGAM_64);
	ofile->fat_header = ofile->vm_addr;
	ofile->fat_archs = NULL;
	ofile->fat_archs_64 = NULL;
	ofile->narch = ~0U;
	ofile->arch_ofile_type = OFILE_UNKNOWN;
	if (ofile->fat_header->magic == FAT_MAGIC
		|| ofile->fat_header->magic == FAT_CIGAM)
		ofile->fat_archs = (struct fat_arch*)(ofile->fat_header + 1);
	else
		ofile->fat_archs_64 = (struct fat_arch_64*)(void *)(ofile->fat_header + 1);
	if (get_host_byte_sex() != BIG_ENDIAN_BYTE_SEX)
		return (ofile_swap_fat_hdrs(ofile));
	(void)print_archs_names;
	return (0);
}
