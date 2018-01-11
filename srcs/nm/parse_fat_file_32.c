/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:15:57 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 14:49:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t					parse_fat_file_32(void *file_map
										, size_t file_size
										, t_ofile *ofile)
{
	struct fat_arch	*archs;

	archs = (struct fat_arch*)(ofile->fat_hdr + 1);
	if (archs->offset + archs->size >= file_size)
		return (-1);
	ofile->hdr = (struct mach_header*)(void*)((uint8_t*)file_map + archs->offset);
	return (1);
}
