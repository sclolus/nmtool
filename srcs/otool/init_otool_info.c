/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_otool_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 05:09:52 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 05:12:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

inline void				cleanup_otool_info(t_otool_info *info)
{
	free(info->secs);
	free(info->secs_64);
	free(info->segs_64);
	free(info->segs);
}

int32_t					init_otool_info(t_ofile *ofile,
											t_otool_info *otool_info)
{
	ft_bzero(otool_info, sizeof(t_otool_info));
	assert(ofile->mh || ofile->mh_64);
	if (ofile->mh)
	{
		otool_info->secs = ofile_get_sections(ofile, &otool_info->nsects);
		otool_info->segs = ofile_get_segments(ofile, &otool_info->nsegs);
	}
	else
	{
		otool_info->secs_64 = ofile_get_sections_64(ofile, &otool_info->nsects);
		otool_info->segs_64 = ofile_get_segments_64(ofile, &otool_info->nsegs);
	}
	otool_info->text_nsec = otool_find_section(otool_info, SEG_TEXT, SECT_TEXT);
	return (0);
}
