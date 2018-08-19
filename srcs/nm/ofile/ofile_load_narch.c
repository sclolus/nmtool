/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_load_next_macho.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 05:34:06 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 11:23:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	ofile_load_narch(t_ofile *ofile, uint32_t narch)
{
	assert(narch < ofile->fat_header->nfat_arch);
	assert(ofile->fat_archs || ofile->fat_archs_64);
	if (narch >= ofile->fat_header->nfat_arch)
		return (-1);
	ofile->object_addr = NULL;
	ofile->object_size = 0;
	ofile->obj_byte_sex = UNKNOWN_BYTE_SEX;
	ofile->must_be_swapped = false;
	ofile->mh = NULL;
	ofile->mh_64 = NULL;
	ofile->load_commands = NULL;
	ofile->narch = narch;
	if (ofile->fat_archs)
		load_macho_ofile(ofile,
		(void *)((uint8_t *)ofile->vm_addr + ofile->fat_archs[narch].offset), ofile->fat_archs[narch].size);
	else
		load_macho_ofile(ofile,
		(void *)((uint8_t *)ofile->vm_addr + ofile->fat_archs_64[narch].offset), ofile->fat_archs[narch].size);
	return (0);
}
