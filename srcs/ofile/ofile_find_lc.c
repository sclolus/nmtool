/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:50:10 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 06:55:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct load_command	*ofile_find_lc(t_ofile *ofile, uint32_t cmd)
{
	uint32_t			i;
	uint32_t			ncmds;
	struct load_command	*cur_lc;

	if (ofile->load_commands == NULL || (ofile->mh == NULL && ofile->mh_64 == NULL))
		return (NULL);
	i = 0;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	cur_lc = ofile->load_commands;
	while (i < ncmds)
	{
		if (-1 == ofile_object_check_addr_size(ofile, cur_lc, sizeof(struct load_command))
			|| -1 == ofile_object_check_addr_size(ofile, cur_lc, cur_lc->cmdsize))
			return (NULL);
		if (cmd == cur_lc->cmd || (LC_REQ_DYLD | cmd) == cur_lc->cmd)
			return (cur_lc);
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc + cur_lc->cmdsize);
		i++;
	}
	return (NULL);
}
