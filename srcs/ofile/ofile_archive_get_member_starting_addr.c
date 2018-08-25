/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_archive_get_member_starting_addr.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 05:26:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:20:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void		*ofile_archive_get_member_starting_addr(t_ofile *ofile)
{
	uint8_t		*addr;

	assert(ofile->archive_start_addr && ofile->archive_member_header_addr);
	addr = ((uint8_t *)ofile->archive_member_header_addr + 60
			+ (ofile->archive_member_header.long_name
			? ((uint64_t)ofile->archive_member_header.name_length | 0x4)
			: 0));
	return (addr);
}
