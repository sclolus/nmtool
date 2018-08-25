/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_get_segments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 03:46:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:26:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static void				fill_segments(struct segment_command **segs,
								uint32_t nsegs,
								t_ofile *ofile)
{
	struct load_command	*cur_lc;
	uint32_t			i;
	uint32_t			ncmds;

	assert((ofile->mh || ofile->mh_64) && ofile->load_commands);
	i = 0;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	cur_lc = ofile->load_commands;
	while (i < nsegs)
	{
		if (cur_lc->cmd == LC_SEGMENT)
			segs[i++] = (struct segment_command*)(void*)cur_lc;
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc
												+ cur_lc->cmdsize);
	}
}

struct segment_command	**ofile_get_segments(t_ofile *ofile,
											uint32_t *return_nsegs)
{
	uint32_t				nsegs;
	struct segment_command	**segs;

	assert((ofile->mh || ofile->mh_64) && ofile->load_commands);
	nsegs = ofile_get_nsegs(ofile);
	*return_nsegs = 0;
	if (NULL == (segs = malloc(sizeof(struct segment_command *) * nsegs)))
		exit(EXIT_FAILURE);
	fill_segments(segs, nsegs, ofile);
	*return_nsegs = nsegs;
	return (segs);
}
