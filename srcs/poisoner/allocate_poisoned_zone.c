/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_poisoned_zone.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 06:31:09 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 06:41:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

void	*allocate_poisoned_zone(const t_ofile *ofile)
{
	void	*map;

	if (MAP_FAILED == (map = mmap(NULL
					, ofile->file_size
					, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0)))
	{
		perror("allocate_poisoned_zone()");
		exit(EXIT_FAILURE);
	}
	memcpy(map, ofile->vm_addr, ofile->file_size);
	poisoned_zone_vm_addr = map;
	return (map);
}
