/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_get_n_lc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 01:17:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 01:33:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct load_command	*ofile_get_n_lc(t_ofile *ofile, uint32_t n)
{
	uint32_t			i;
	uint32_t			ncmds;
	struct load_command	*cur_lc;


	assert(ofile->load_commands && (ofile->mh || ofile->mh_64));
	i = 0;
	ncmds = ofile->mh ? ofile->mh->ncmds : ofile->mh_64->ncmds;
	cur_lc = ofile->load_commands;
	while (i < ncmds)
	{
		if (-1 == ofile_object_check_addr_size(ofile, cur_lc, sizeof(struct load_command))
			|| -1 == ofile_object_check_addr_size(ofile, cur_lc, cur_lc->cmdsize))
			return (NULL);
		if (n == 0)
			return (cur_lc);
		n--;
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc + cur_lc->cmdsize);
		i++;
	}
	return (NULL);
}
