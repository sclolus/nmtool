/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_macho_ofile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:01:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 12:34:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	load_macho_ofile(t_ofile *ofile, void *object_addr, uint64_t object_size) // change the return type
{
	ofile->object_addr = object_addr;
	ofile->object_size = object_size;
	if (-1 == ofile_file_check_addr_size(ofile, ofile->object_addr, ofile->object_size))
		return (-1);
	ofile->obj_byte_sex = get_macho_byte_sex(((struct mach_header *)ofile->object_addr));
	if (ofile->obj_byte_sex == UNKNOWN_BYTE_SEX)
	{
		ft_dprintf(2, "Unknown endian found for mach-o object, aborting...\n");
		return (-1);
	}
	if (ofile->obj_byte_sex != get_host_byte_sex())
		ofile->must_be_swapped = true;
	else
		ofile->must_be_swapped = false;
	if (set_ofile_mh(ofile) == NULL)
	{
		ft_dprintf(2, "Malformed object file, the mach-o header is truncated or non-existant\n");
		return (-1);
	}
	if (set_ofile_load_commands(ofile) == NULL)
	{
		ft_dprintf(2, "Malformed object file, there are no load commands\n");
		return (-1);
	}
	if (ofile->must_be_swapped)
	{
		ofile_swap_macho_hdr(ofile);
		if (-1 == ofile_swap_macho_load_commands(ofile))
			return (-1);
	}
	if (-1 == ofile_check_object_integrity(ofile))
		return (-1);
	if (ofile->must_be_swapped)
		ofile_swap_macho_symtab(ofile);
	return (0);
}
