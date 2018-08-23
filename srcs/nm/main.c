/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:39:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:20:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"


int	main(int argc, char **argv)
{
	t_ofile		*ofile;
	t_nm_flags	*nm_flags;
	uint32_t	i;

	if (!(nm_flags = parse_flags(argc, argv)))
		return (EXIT_FAILURE);
	i = 0;
	while (i < nm_flags->nbr_files)
	{
		if (!(ofile = get_ofile(nm_flags->files[i])))
		{
			i++;
			continue ;
		}
		if (ofile->ofile_type == OFILE_UNKNOWN)
			ft_error(5, (char *[]){argv[0], ": ",
						nm_flags->files[i], " ",
						ERR_UNKNOWN_FILE_FORMAT}, 0);
		nm(ofile, nm_flags);
		if (munmap_file(ofile))
		{
			ft_dprintf(2, "Failed to munmap file\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
