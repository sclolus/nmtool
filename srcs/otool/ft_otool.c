/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:25:18 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/05 10:30:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

void	ft_otool(char *filename)
{
	void		*file_map;
	int			fd;
	struct stat	file_stat;

	if (-1 == (fd = open(filename, O_RDONLY)))
		ft_error_exit(2, (char*[]){"Failed to open(): ", filename}, EXIT_FAILURE);
	if (-1 == (fstat(fd, &file_stat)))
		ft_error_exit(2, (char*[]){"Failed to fstat(): ", filename}, EXIT_FAILURE);
	file_map = map_otool_file(fd, (size_t)file_stat.st_size);

}
