/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_get_sections_64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:54:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:07:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static uint32_t		fill_sections_from_seg(struct load_command *lc,
										struct section_64 **secs,
										uint32_t count)
{
	uint32_t					i;
	struct segment_command_64	*sc;

	i = 0;
	sc = (struct segment_command_64 *)(void *)lc;
	while (i < sc->nsects)
		secs[count++] = (struct section_64*)(sc + 1) + i++;
	return (count);
}

struct section_64	**ofile_get_sections_64(t_ofile *ofile,
											uint32_t *return_nsects)
{
	uint32_t			i;
	uint32_t			nsects;
	struct section_64	**secs;
	struct load_command	*cur_lc;

	i = 0;
	assert(ofile && ofile->load_commands);
	*return_nsects = 0;
	nsects = get_nsects_64(ofile);
	if (NULL == (secs = malloc(sizeof(struct section_64 *) * nsects)))
		exit(EXIT_FAILURE);
	cur_lc = ofile->load_commands;
	while (i < nsects)
	{
		if (cur_lc->cmd == LC_SEGMENT_64)
			i = fill_sections_from_seg(cur_lc, secs, i);
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc
												+ cur_lc->cmdsize);
	}
	*return_nsects = nsects;
	return (secs);
}
