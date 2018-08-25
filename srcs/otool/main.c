/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:49:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 06:34:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	process_files(int argc, char **argv)
{
	uint64_t	i;
	t_ofile		*ofile;

	i = 1;
	while ((int32_t)i < argc)
	{
		if (!(ofile = get_ofile(argv[i])))
		{
			i++;
			continue ;
		}
		if (ofile->ofile_type == OFILE_UNKNOWN)
		{
			ft_printf("%s: is not an object file\n", ofile->file_name);
			i++;
			continue ;
		}
		otool(ofile);
		if (munmap_file(ofile))
			return (EXIT_FAILURE);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc == 1)
	{
		print_otool_usage();
		exit(EXIT_FAILURE);
	}
	return (process_files(argc, argv));
}
