/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:43:50 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:34:22 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline void	handle_endianness(void *file_map
									, t_ofile *ofile)
{
	if (FAT_CIGAM == *(uint32_t*)file_map)
		swap_fat(ofile->fat_hdr);
	else if (FAT_CIGAM_64 == *(uint32_t*)file_map)
		swap_fat(ofile->fat_hdr);
}

int32_t			parse_fat_file(void *file_map
						, size_t file_size
						, t_ofile *ofile)
{
	ofile->fat_hdr = (struct fat_header*)file_map;
	handle_endianness(file_map, ofile);
	if (FAT_MAGIC == ofile->fat_hdr->magic)
	{
		ofile->is_64 = 0;
		return (parse_fat_file_32(file_size, ofile));
	}
	else if (FAT_MAGIC_64 == ofile->fat_hdr->magic)
	{
		ofile->is_64 = 1;
		return (parse_fat_file_64(file_size, ofile));
	}
	else
	{
		ofile->fat_hdr = NULL;
		return (0);
	}
}
