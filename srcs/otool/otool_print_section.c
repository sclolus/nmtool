/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_print_section.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 05:24:12 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 06:28:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		dump_section_line(void *addr,
								uint32_t n_bytes,
								cpu_type_t cputype)
{
	uint32_t	i;

	i = 0;
	if (cputype != CPU_TYPE_POWERPC)
		while (i < n_bytes)
		{
			ft_printf("%02x ", ((uint8_t*)addr)[i]);
			i++;
		}
	else
		while (i < n_bytes)
		{
			ft_printf("%08x ", swap_int32(((uint32_t*)addr)[i / 4]));
			i += 4;
		}
	ft_printf("\n");
}

int32_t			otool_print_section(t_ofile *ofile,
									t_otool_info *otool_info,
									uint32_t nsec)
{
	void		*section_addr;
	uint32_t	size;
	uint32_t	i;

	assert(otool_info->secs && otool_info->segs);
	if (-1 == ofile_object_check_addr_size(ofile,
				(uint8_t*)ofile->object_addr + otool_info->secs[nsec]->offset,
				otool_info->secs[nsec]->size))
		return (-1);
	section_addr = (void *)((uint8_t*)ofile->object_addr
							+ otool_info->secs[nsec]->offset);
	size = otool_info->secs[nsec]->size;
	i = 0;
	ft_printf("Contents of (%s,%s) section\n", otool_info->secs[nsec]->segname,
										otool_info->secs[nsec]->sectname);
	while (i < size)
	{
		ft_printf("%08x\t", otool_info->secs[nsec]->addr + i);
		dump_section_line((uint8_t*)section_addr + i,
						size - i > 16 ? 16 : size - i
						, ofile->mh->cputype);
		i += 16;
	}
	return (0);
}
