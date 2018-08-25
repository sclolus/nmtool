/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_handle_archive.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 16:25:49 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 16:26:02 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int32_t	otool_handle_archive(t_ofile *ofile)
{
	uint64_t		i;
	bool			soft_error;

	i = 0;
	soft_error = 0;
	while (i < ofile->nran)
	{
		if (-1 == ofile_load_narchive_member(ofile, i, &soft_error))
		{
			if (soft_error)
				return (0);
			i++;
			continue ;
		}
		ft_printf("%s(%s):\n", ofile->file_name
			, ofile->archive_member_header.member_name);
		if (-1 == otool_process_obj(ofile))
			return (-1);
		i++;
	}
	return (0);
}
