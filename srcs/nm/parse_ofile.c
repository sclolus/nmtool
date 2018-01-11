/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ofile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:02:31 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 18:09:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_ofile	*parse_ofile(void *file_map, size_t file_size)
{
	t_ofile	*ofile;
	int32_t	ret;

	if (sizeof(struct mach_header) >= file_size)
		return (NULL);
	if (!(ofile = (t_ofile*)ft_memalloc(sizeof(t_ofile))))
		return (NULL);
	ofile->file_map = file_map;
	ofile->obj_size = file_size;
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
	}
	ret = -1 ;//
	if (ofile->is_64)
		ret = parse_ofile_64(ofile);
	else if (!ofile->is_64)
		ret = parse_ofile_32(ofile);
	if (ret == -1)
	{
		free(ofile);
		return (NULL);
	}
	return (ofile);
}
