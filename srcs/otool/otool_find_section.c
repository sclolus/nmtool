/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_find_section.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 05:08:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 05:08:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

uint32_t	otool_find_section(t_otool_info *otool_info,
							char *seg_name,
							char *sec_name)
{
	uint32_t	i;

	assert(otool_info->secs || otool_info->secs_64);
	i = 0;
	if (otool_info->secs)
	{
		while (i < otool_info->nsects)
		{
			if (ft_strequ(seg_name, otool_info->secs[i]->segname)
				&& ft_strequ(sec_name, otool_info->secs[i]->sectname))
				return (i);
			i++;
		}
	}
	else
	{
		while (i < otool_info->nsects)
		{
			if (ft_strequ(seg_name, otool_info->secs_64[i]->segname)
				&& ft_strequ(sec_name, otool_info->secs_64[i]->sectname))
				return (i);
			i++;
		}
	}
	return (NO_SECT_FOUND);
}
