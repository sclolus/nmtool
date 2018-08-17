/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:39:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 03:26:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"


int	main(int argc, char **argv)
{
	t_ofile		*ofile;
	t_nm_flags	*nm_flags;
	uint32_t	i;

	if (argc == 1)
	{
		ft_put_nm_usage();
		return (EXIT_FAILURE);
	}
	if (!(nm_flags = parse_flags(argc, argv)))
		return (EXIT_FAILURE);
	i = 0;
	while (i < nm_flags->nbr_files)
	{
		if (!(ofile = get_ofile(nm_flags->files[i])))
		{
			perror(NULL);
			return (EXIT_FAILURE);
		}
		if (-1 == nm(ofile, nm_flags))
			return (EXIT_FAILURE);
		if (munmap_file(ofile))
		{
			perror(NULL);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
