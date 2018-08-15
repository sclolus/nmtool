/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 21:48:53 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/15 21:49:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	*map_file(char *filename, uint64_t *file_size)
{
	int			fd;
	void		*map;
	struct stat	stats;

	if (-1 == (fd = open(filename, O_RDONLY)))
		return (NULL);// put error message
	if (-1 == (fstat(fd, &stats)))
		return (NULL);// put error message
	if (stats.st_size <= 0)
		return (NULL);
	if (MAP_FAILED == (map = mmap(NULL, (uint64_t)stats.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)))
		return (NULL);// put error message
	*file_size = (uint64_t)stats.st_size;
	return (map);
}
