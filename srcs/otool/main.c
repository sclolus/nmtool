/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:49:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:53:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	main(int argc, char **argv)
{
	uint64_t	i;
	t_ofile		*ofile;

	if (argc == 1)
	{
		print_otool_usage();
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (i < argc)
	{
		if (!(ofile = get_ofile(argv[i])))
		{
			i++;
			continue ;
		}
		if (ofile->ofile_type == OFILE_UNKNOWN)
		{
			ft_error(5, (char *[]){argv[0], ": ",
						argv[i], " ",
						ERR_UNKNOWN_FILE_FORMAT}, 0);
			i++;
			continue ;
		}
		otool(ofile);
		if (munmap_file(ofile))
		{
			ft_dprintf(2, "Failed to munmap file\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
