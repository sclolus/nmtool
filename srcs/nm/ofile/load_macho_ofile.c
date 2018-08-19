/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_macho_ofile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:01:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 11:27:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	load_macho_ofile(t_ofile *ofile, void *object_addr, uint64_t object_size) // change the return type
{
	ofile->object_addr = object_addr;
	ofile->object_size = object_size;
	if (-1 == ofile_file_check_addr_size(ofile, ofile->object_addr, ofile->object_size))
	{
		dprintf(2, "Object file is malformed\n"); // change all of this
		abort();
	}
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
	if (set_ofile_mh(ofile) == NULL)
	{
		dprintf(2, "Malformed object file, the mach-o header is truncated or non-existant\n");
		exit(EXIT_FAILURE);
	}
	if (set_ofile_load_commands(ofile) == NULL)
	{
		dprintf(2, "Malformed object file, there are no load commands\n");
		exit(EXIT_FAILURE);
	}
	if (ofile->must_be_swapped)
	{
		ofile_swap_macho_hdr(ofile);
		ofile_swap_macho_load_commands(ofile);
	}
}
