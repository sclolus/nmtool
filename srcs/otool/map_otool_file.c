/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_otool_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:24:57 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/05 10:28:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

inline void	*map_otool_file(int fd, size_t size)
{
	void	*map;

	if (MAP_FAILED == (map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)))
		ft_error_exit(1, (char*[]){"Failed to mmap() file"}, EXIT_FAILURE);
	return (map);
}
