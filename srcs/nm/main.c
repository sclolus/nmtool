/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:39:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 11:43:54 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	process_files(t_nm_flags *nm_flags, char *bin_name)
{
	t_ofile		*ofile;
	uint32_t	i;

	i = 0;
	while (i < nm_flags->nbr_files)
	{
		if (!(ofile = get_ofile(nm_flags->files[i])))
		{
			i++;
			continue ;
		}
		if (ofile->ofile_type == OFILE_UNKNOWN)
		{
			ft_error(5, (char *[]){bin_name, ": ",
						nm_flags->files[i++], " ",
						ERR_UNKNOWN_FILE_FORMAT}, 0);
			continue ;
		}
		nm(ofile, nm_flags);
		if (munmap_file(ofile))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_nm_flags	*nm_flags;

	if (!(nm_flags = parse_flags(argc, argv)))
	{
		ft_put_nm_usage();
		return (EXIT_FAILURE);
	}
	return (process_files(nm_flags, argv[0]));
}
