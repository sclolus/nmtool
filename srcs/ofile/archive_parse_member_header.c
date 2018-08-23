/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_archive_parse_member_header.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 06:09:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:20:28 by sclolus          ###   ########.fr       */
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
			ft_dprintf(2, "Invalid member_name size\n");
			return (-1);
		}
		ofile->archive_member_header.member_name = (uint8_t*)ofile->archive_member_header_addr + 60;
		ofile->archive_member_header.long_name = true;
	}
	else
	{
		ofile->archive_member_header.member_name = (uint8_t*)ofile->archive_member_header_addr;
		ofile->archive_member_header.name_length = 16;
		ofile->archive_member_header.long_name = false;
	}
	return (0);
}

int32_t	archive_parse_member_header(t_ofile *ofile)
{
	uint8_t			*member_hdr_addr;

	member_hdr_addr = (uint8_t *)ofile->archive_member_header_addr;
	if (-1 == parse_archive_member_name(ofile))
		return (-1);
	ofile->archive_member_header.st_time = (uint8_t*)(member_hdr_addr + 16);
	ofile->archive_member_header.st_uid = ft_atou((const char *)member_hdr_addr + 28);
	ofile->archive_member_header.st_gid = ft_atou((const char *)member_hdr_addr + 34);
	ofile->archive_member_header.st_mode = ft_atohu_base((const char *)member_hdr_addr + 40, "01234567");
	ofile->archive_member_header.st_size = ft_atoll((const char *)member_hdr_addr + 48);
	if (ofile->archive_member_header.st_size < 0)
	{
		ft_dprintf(2, "Invalid st_size in archive member\n");
		return (-1);
	}
	return (0);
}
