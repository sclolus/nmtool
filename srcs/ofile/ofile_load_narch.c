/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_load_next_macho.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 05:34:06 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 23:03:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	ofile_load_narch(t_ofile *ofile, uint32_t narch)
{
	void		*addr;
	uint64_t	object_size;

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
	{
		if (-1 == ofile_file_check_addr_size(ofile, ofile->fat_archs + narch, sizeof(struct fat_arch)))
		{
			dprintf(2, "Malformed fat file, the fat header is truncated or would extend beyond the file\n");
			return (-1);
		}
		addr = (void *)((uint8_t *)ofile->vm_addr + ofile->fat_archs[narch].offset);
		object_size = ofile->fat_archs[narch].size;
	}
	else
	{
		if (-1 == ofile_file_check_addr_size(ofile, ofile->fat_archs_64 + narch, sizeof(struct fat_arch_64)))
		{
			dprintf(2, "Malformed fat file, the fat header is truncated or would extend beyond the file\n");
			return (-1);
		}
		addr = (void *)((uint8_t *)ofile->vm_addr + ofile->fat_archs_64[narch].offset);
		object_size = ofile->fat_archs_64[narch].size;
	}
	return (load_macho_ofile(ofile, addr, object_size));
}
