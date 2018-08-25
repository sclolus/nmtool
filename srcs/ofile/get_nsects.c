/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:24:47 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:13:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

uint32_t	get_nsects(t_ofile *ofile)
{
	struct load_command	*cur_lc;
	uint32_t			i;
	uint32_t			nsects;
	uint32_t			ncmds;

	if (ofile->mh == NULL && ofile->mh_64 == NULL)
		return (0);
	cur_lc = ofile->load_commands;
	i = 0;
	nsects = 0;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	while (i < ncmds)
	{
		if (cur_lc->cmd == LC_SEGMENT)
			nsects += ((struct segment_command*)cur_lc)->nsects;
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc
												+ cur_lc->cmdsize);
		i++;
	}
	return (nsects);
}
