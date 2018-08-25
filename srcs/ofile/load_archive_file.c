/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_archive_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 02:11:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 14:02:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	load_archive_file(t_ofile *ofile, void *archive_addr)
{
	ofile->archive_start_addr = archive_addr;
	ofile->archive_member_header_addr = (void *)
		((uint8_t*)ofile->archive_start_addr + sizeof(STATIC_LIB_MAGIC) - 1);
	ofile->symdef_addr = NULL;
	ofile->members = NULL;
	ofile->ranlibs = NULL;
	ofile->ranlibs_64 = NULL;
	if (-1 == archive_parse_member_header(ofile))
		return (-1);
	ofile->members = ofile->archive_member_header_addr;
	if (-1 == set_archive_symdef(ofile))
		return (-1);
	return (0);
}
