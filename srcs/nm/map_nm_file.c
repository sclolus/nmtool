/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nm_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 02:17:00 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 17:17:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	*map_nm_file(int fd, size_t size)
{
	void	*map;

	if (MAP_FAILED == (map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0)))
	{
		ft_error(1, (char*[]){"Failed to mmap() file"}, 0);
		return (NULL);
	}
	return (map);
}
