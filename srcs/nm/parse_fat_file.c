/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:43:50 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 22:39:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t			parse_fat_file(void *file_map
						, size_t file_size
						, t_ofile *ofile)
{
	ofile->fat_hdr = (struct fat_header*)file_map;
	if (FAT_CIGAM == *(uint32_t*)file_map)
	{
		ofile->is_64 = 0;
		return (parse_fat_file_32(file_map, file_size, ofile));
	}
	else if (FAT_MAGIC_64 == *(uint32_t*)file_map)
	{
		ofile->is_64 = 1;
		return (parse_fat_file_64(file_map, file_size, ofile));
	}
	else
		return (-1);
}
