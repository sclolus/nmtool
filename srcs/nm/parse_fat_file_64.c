/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file_64.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:23:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 19:34:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t					parse_fat_file_64(size_t file_size
										, t_ofile *ofile)
{
	struct fat_arch_64	*archs;

	if (!(archs = get_fat_host_arch_64(ofile)))
	archs = (struct fat_arch_64*)(void*)(ofile->fat_hdr + 1);
	if (archs->offset + archs->size > file_size)
		return (-1);
	return (parse_macho_header((void*)((uint64_t)ofile->file_map
							+ archs->offset)
							, file_size, ofile));
}
