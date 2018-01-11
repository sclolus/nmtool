/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:23:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 14:56:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t					parse_fat_file_64(void *file_map
										, size_t file_size
										, t_ofile *ofile)
{
	struct fat_arch_64	*archs;

	archs = (struct fat_arch_64*)(void*)(ofile->fat_hdr + 1);
	if (archs->offset + archs->size >= file_size)
		return (-1);
	ofile->hdr64 = (struct mach_header_64*)(void*)((uint8_t*)file_map + archs->offset);
	return (1);
}
