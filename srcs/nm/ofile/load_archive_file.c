/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_archive_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 02:11:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:14:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static inline int32_t	parse_archive_member_name(t_ofile *ofile)
{
	if (!ft_memcmp(ofile->archive_member_header_addr, LONG_ARCHIVE_NAME_MAGIC, sizeof(LONG_ARCHIVE_NAME_MAGIC) - 1))
	{
		ofile->archive_member_header.name_length = ft_atou((char *)ofile->archive_member_header_addr + sizeof(LONG_ARCHIVE_NAME_MAGIC) - 1);
		if (ofile->archive_member_header.name_length < 0)
		{
			dprintf(2, "Invalid member_name size\n");
			return (-1);
		}
		ofile->archive_member_header.member_name = (uint8_t*)ofile->archive_member_header_addr + 60;
	}
	else
	{
		ofile->archive_member_header.member_name = (uint8_t*)ofile->archive_member_header_addr;
		ofile->archive_member_header.name_length = 16;
	}
	return (0);
}

static inline int32_t	archive_parse_member_header(t_ofile *ofile)
{
	uint8_t			*member_hdr_addr = (uint8_t *)ofile->archive_member_header_addr;

	if (-1 == parse_archive_member_name(ofile))
		return (-1);
	ofile->archive_member_header.st_time = (uint8_t*)(member_hdr_addr + 16);
	ofile->archive_member_header.st_uid = ft_atou((const char *)member_hdr_addr + 28);
	ofile->archive_member_header.st_gid = ft_atou((const char *)member_hdr_addr + 34);
	ofile->archive_member_header.st_mode = ft_atohu_base((const char *)member_hdr_addr + 40, "01234567");
	ofile->archive_member_header.st_size = ft_atoll((const char *)member_hdr_addr + 48);
	if (ofile->archive_member_header.st_size < 0)
	{
		dprintf(2, "Invalid st_size in archive member\n");
		return (-1);
	}
	return (0);
}

void	load_archive_file(t_ofile *ofile)
{

	ofile->archive_start_addr = ofile->vm_addr;
	ofile->archive_member_header_addr = (void *)((uint8_t*)ofile->archive_start_addr + sizeof(STATIC_LIB_MAGIC) - 1);
	write(1, ofile->archive_member_header_addr, 60);
	if (-1 == archive_parse_member_header(ofile))
		assert(0);
}
