/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_get_nsegs_64.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 03:52:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 03:53:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

uint32_t	ofile_get_nsegs_64(t_ofile *ofile)
{
	struct load_command *cur_lc;
	uint32_t			i;
	uint32_t			nsegs;
	uint32_t			ncmds;


	assert((ofile->mh || ofile->mh_64) && ofile->load_commands);
	i = 0;
	nsegs = 0;
	cur_lc = ofile->load_commands;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	while (i < ncmds)
	{
		if (cur_lc->cmd == LC_SEGMENT_64)
			nsegs++;
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc + cur_lc->cmdsize);
		i++;
	}
	return (nsegs);
}
