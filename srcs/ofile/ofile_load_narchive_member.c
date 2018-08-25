/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_load_narchive_member.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 06:05:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 21:34:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static inline void	*find_archive_member(t_ofile *ofile, uint64_t n_member)
{
	uint32_t	i;

	ofile->archive_member_header_addr = ofile->members;
	i = 0;
	while (i < n_member + 1)
	{
		if (-1 == archive_parse_member_header(ofile))
			return (NULL);
		ofile->archive_member_header_addr = (void *)((uint8_t *)
									ofile->archive_member_header_addr
									+ 60
									+ (ofile->archive_member_header.st_size));
		i++;
	}
	return (ofile->archive_member_header_addr);
}

int32_t				ofile_load_narchive_member(t_ofile *ofile,
											uint64_t n_member,
											bool *soft_error)
{
	assert(ofile->symdef_addr && ofile->ranlibs || ofile->ranlibs_64);
	if (n_member >= ofile->nmembers && soft_error)
		*soft_error = 1;
	ofile->archive_member_header_addr = NULL;
	ft_bzero(&ofile->archive_member_header, sizeof(t_member_header));
	ofile->archive_member_header_addr = find_archive_member(ofile, n_member);
	if (-1 == archive_parse_member_header(ofile)
		|| !(ofile->archive_member_header.st_size > 0))
		return (-1);
	return (load_macho_ofile(ofile,
							ofile_archive_get_member_starting_addr(ofile),
							(uint64_t)ofile->archive_member_header.st_size));
}
