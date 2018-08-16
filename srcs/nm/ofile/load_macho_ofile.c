/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_macho_ofile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:01:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 01:49:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	load_macho_ofile(t_ofile *ofile, void *object_addr) // change the return type
{
	ofile->object_addr = object_addr;
	if (ofile->ofile_type == OFILE_FAT)
		ofile->object_size = ofile->fat_archs[ofile->narch].size;
	else
		ofile->object_size = ofile->file_size;
	ofile->obj_byte_sex = get_macho_byte_sex(((struct mach_header *)ofile->object_addr));
	if (ofile->obj_byte_sex == UNKNOWN_BYTE_SEX)
	{
		dprintf(2, "Unknown endian found for mach-o object, aborting...\n");
		abort();
	}
	if (ofile->obj_byte_sex != get_host_byte_sex())
		ofile->must_be_swapped = true;
	else
		ofile->must_be_swapped = false;
	assert(set_ofile_mh(ofile));
	assert(set_ofile_load_commands(ofile));
	if (ofile->must_be_swapped)
	{
		ofile_swap_macho_hdr(ofile);
		ofile_swap_macho_load_commands(ofile);
	}
}
