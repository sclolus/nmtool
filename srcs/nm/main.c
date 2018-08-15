/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:39:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/15 21:49:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"


int	main(int argc, char **argv)
{
	t_ofile	*ofile;

	if (argc != 2)
		return (EXIT_FAILURE);
	if (!(ofile = get_ofile(argv[1])))
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	return (0);
}
