/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_macho_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:16:40 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:38:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline static void		handle_endianness(void *file_map
									, t_ofile *ofile)
{
	if (MH_CIGAM == *(uint32_t*)file_map)
	{
		ofile->hdr = file_map;
		swap_ofile_endianness(ofile);
	}
	else if (MH_CIGAM_64 == *(uint32_t*)file_map)
	{
		ofile->hdr64 = file_map;
		swap_ofile_endianness(ofile);
	}
}

int32_t					parse_macho_header(void *file_map
									, size_t file_size
									, t_ofile *ofile)
{
	handle_endianness(file_map, ofile);
	if (MH_MAGIC == *(uint32_t*)file_map)
	{
		ofile->is_64 = 0;
		ofile->hdr = file_map;
		if (ofile->hdr->sizeofcmds + sizeof(ofile->hdr) >= file_size)
			return (-1);
	}
	else if (MH_MAGIC_64 == *(uint32_t*)file_map)
	{
		ofile->is_64 = 1;
		ofile->hdr64 = file_map;
		if (ofile->hdr64->sizeofcmds + sizeof(ofile->hdr64) >= file_size)
			return (-1);
	}
	else
		return (-1);
	return (0);
}
