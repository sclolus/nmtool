/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 22:15:57 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 19:34:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include "mach-o/arch.h"

int32_t					parse_fat_file_32(size_t file_size
										, t_ofile *ofile)
{
	struct fat_arch	*archs;
	uint32_t		i;

	i = 0;
	if (!(archs = get_fat_host_arch(ofile)))
	{
		archs = (struct fat_arch*)(ofile->fat_hdr + 1);
	}
	if (archs->offset + archs->size > file_size)
		return (-1);
	return (parse_macho_header((void*)((uint64_t)ofile->file_map
							+ archs->offset)
							, file_size, ofile));
}
