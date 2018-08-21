/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ofile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:50:03 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 23:01:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

t_ofile	*get_ofile(char *filename)
{
	t_ofile	*ofile;
	void	*map;

	if (!(ofile = malloc(sizeof(t_ofile))))
		return (NULL); // put error_message
	ft_bzero(ofile, sizeof(t_ofile));
	if (!(map = map_file(filename, &ofile->file_size)))
	{
		free(ofile);
		return (NULL);
	}
	ofile->file_name = ft_strdup(filename);
	ofile->vm_addr = map;
	ofile->ofile_type = get_ofile_type(ofile);
	if (ofile->ofile_type == OFILE_FAT)
		load_fat_ofile(ofile);
	else if (ofile->ofile_type == OFILE_ARCHIVE)
		load_archive_file(ofile);
	else if (ofile->ofile_type == OFILE_MACHO)
	{
		if (-1 == load_macho_ofile(ofile, ofile->vm_addr, ofile->file_size))
		{
			munmap_file(ofile);
			return (NULL);
		}
	}
	return (ofile);
}