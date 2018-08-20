/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poison_lc_segment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:46:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 19:59:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

void	poison_lc_segment(struct load_command *lc, t_ofile *ofile)
{
	struct segment_command	*sc;

	(void)ofile;
	sc = (struct segment_command *)lc;
	sc->nsects = (uint32_t)rand();
}

void	poison_lc_segment_64(struct load_command *lc, t_ofile *ofile)
{
	struct segment_command_64 *sc;

	(void)ofile;
	sc = (struct segment_command_64 *)(void*)lc;
	sc->nsects = (uint32_t)rand();
}
