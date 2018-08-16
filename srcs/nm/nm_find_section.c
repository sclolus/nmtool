/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_find_section.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 04:35:16 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 04:47:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint32_t	nm_find_section(t_nm_process_info *nm_info,
							char *seg_name,
							char *sec_name)
{
	uint32_t	i;

	assert(nm_info->secs || nm_info->secs_64);
	i = 0;
	if (nm_info->secs)
	{
		while (i < nm_info->nsects)
		{
			if (ft_strequ(seg_name, nm_info->secs[i]->segname)
				&& ft_strequ(sec_name, nm_info->secs[i]->sectname))
				return (i);
			i++;
		}
	}
	else
	{
		while (i < nm_info->nsects)
		{
			if (ft_strequ(seg_name, nm_info->secs_64[i]->segname)
				&& ft_strequ(sec_name, nm_info->secs_64[i]->sectname))
				return (i);
			i++;
		}
	}
	return (NO_SECT_FOUND);
}
