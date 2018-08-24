/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_print_section_64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 05:32:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 06:17:45 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		dump_section_line(void *addr, uint64_t n_bytes)
{
	uint64_t	i;

	i = 0;
	while (i < n_bytes)
	{
		ft_printf("%02x ", ((uint8_t*)addr)[i]);
		i++;
	}
	ft_printf("\n");
}

int32_t			otool_print_section_64(t_ofile *ofile
									, t_otool_info *otool_info
									, uint32_t nsec)
{
	void		*section_addr;
	uint64_t	size;
	uint64_t	i;

	assert(otool_info->secs_64 && otool_info->segs_64);
	if (-1 == ofile_object_check_addr_size(ofile,
				(uint8_t*)ofile->object_addr + otool_info->secs_64[nsec]->offset,
				otool_info->secs_64[nsec]->size))
		return (-1);
	section_addr = (void *)((uint8_t*)ofile->object_addr + otool_info->secs_64[nsec]->offset);
	size = otool_info->secs_64[nsec]->size;
	i = 0;
	ft_printf("Contents of (%s,%s) section\n", otool_info->secs_64[nsec]->segname,
											otool_info->secs_64[nsec]->sectname);
	while (i < size)
	{
		ft_printf("%016llx\t", otool_info->secs_64[nsec]->addr + i);
		dump_section_line((uint8_t*)section_addr + i, size - i > 16 ? 16 : size - i);
		i += 16;
	}
	return (0);
}
