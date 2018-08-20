/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_addr_to_poisoned_zone.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 06:39:37 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 06:46:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

void	*map_addr_to_poisoned_zone(const t_ofile *ofile, void *addr)
{

	assert(poisoned_zone_vm_addr && ofile->vm_addr);
	return ((void *)((uint8_t*)poisoned_zone_vm_addr +
					((uint8_t*)addr - (uint8_t*)ofile->vm_addr)));
}
