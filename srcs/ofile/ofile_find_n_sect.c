/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_n_sect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:37:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:23:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct section	*ofile_find_n_sect(t_ofile *ofile, uint32_t n)
{
	struct load_command	*cur_lc;
	uint32_t			i;
	uint32_t			nsects;
	uint32_t			ncmds;

	cur_lc = ofile->load_commands;
	i = 0;
	nsects = 0;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	while (i < ncmds)
	{
		if (cur_lc->cmd == LC_SEGMENT)
		{
			if (((struct segment_command*)cur_lc)->nsects + nsects < n)
				nsects += ((struct segment_command*)cur_lc)->nsects;
			else
				return (((struct section *)(void *)((struct segment_command*)
												cur_lc + 1)) + (n - nsects));
		}
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc
												+ cur_lc->cmdsize);
		i++;
	}
	return (NULL);
}
