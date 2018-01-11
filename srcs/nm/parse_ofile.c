/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ofile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:02:31 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 15:09:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static int32_t	parse_macho_header(void *file_map
									, size_t file_size
									, t_ofile *ofile)
{
	if (sizeof(struct mach_header_64) >= file_size)
		return (-1);
	ofile->obj_size = file_size;
	if (MH_MAGIC == *(uint32_t*)file_map)
	{
		ofile->is_64 = 0;
		ofile->hdr = file_map;
		if (ofile->hdr->sizeofcmds + sizeof(ofile->hdr) >= file_size)
			return (-1);
	}
	else if (MH_CIGAM == *(uint32_t*)file_map)
	{
		ofile->is_64 = 0;
		ofile->hdr = file_map;
		swap_ofile_endianness(ofile);
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
	else if (MH_CIGAM_64 == *(uint32_t*)file_map)
	{
		ofile->is_64 = 1;
		ofile->hdr64 = file_map;
		swap_ofile_endianness(ofile);
		if (ofile->hdr64->sizeofcmds + sizeof(ofile->hdr64) >= file_size)
			return (-1);
	}
	else
		return (0);
	return (0);
}

t_ofile	*parse_ofile(void *file_map, size_t file_size)
{
	t_ofile	*ofile;
	int32_t	ret;

	if (!(ofile = (t_ofile*)ft_memalloc(sizeof(t_ofile))))
		return (NULL);
	ofile->file_map = file_map;
	if (-1 == parse_fat_file(file_map, file_size, ofile))
	{
		free(ofile);
		return (NULL);
	}
	else if (ofile->fat_hdr == NULL)
	{
		if (-1 == parse_macho_header(file_map, file_size, ofile))
		{
			free(ofile);
			return (NULL);
		}
		ret = 0;//
		if (ofile->is_64)
			ret = parse_ofile_64(file_map, file_size, ofile);
		else
			ret = parse_ofile_32(file_map, file_size, ofile);
		if (ret == -1)
		{
			free(ofile);
			return (NULL);
		}
	}
	return (ofile);
}
