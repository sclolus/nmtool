/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ofile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:50:03 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 00:10:53 by sclolus          ###   ########.fr       */
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
		return (NULL);
	ofile->file_name = ft_strdup(filename);
	ofile->vm_addr = map;
	ofile->ofile_type = get_ofile_type(ofile);
	printf("This is a %s\n", get_ofile_type_name(ofile->ofile_type));
	if (ofile->ofile_type == OFILE_FAT)
		load_fat_ofile(ofile);
	else if (ofile->ofile_type == OFILE_ARCHIVE)
	{
		dprintf(2, "Archive handling not implemented\n");
		exit(EXIT_FAILURE);
	}
	else if (ofile->ofile_type == OFILE_MACHO)
	{
		load_macho_ofile(ofile, ofile->vm_addr);
		printf("Cpu: %s\n", get_cputype_name(ofile->mh_64->cputype));
	}
	return (ofile);
}
