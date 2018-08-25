/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nsects_64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:56:19 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:14:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

uint32_t	get_nsects_64(t_ofile *ofile)
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
		if (cur_lc->cmd == LC_SEGMENT_64)
			nsects += ((struct segment_command_64 *)(void *)cur_lc)->nsects;
		cur_lc = (struct load_command *)(void *)((uint8_t *)cur_lc
												+ cur_lc->cmdsize);
		i++;
	}
	return (nsects);
}
