/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deallocate_poisoned_zone.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 06:36:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 06:41:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

int	deallocate_poisoned_zone(const t_ofile *ofile)
{
	int	ret;

	ret = munmap(poisoned_zone_vm_addr, ofile->file_size | (uint64_t)getpagesize());
	poisoned_zone_vm_addr = NULL;
	return (ret);
}
