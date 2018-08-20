/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lc_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 01:35:18 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 02:06:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	swap_lc_segment(struct load_command *lc)
{
	struct segment_command	*sc;
	uint32_t				i;

	sc = (struct segment_command *)lc;
	sc->vmaddr = swap_int32(sc->vmaddr);
	sc->vmsize = swap_int32(sc->vmsize);
	sc->fileoff = swap_int32(sc->fileoff);
	sc->filesize = swap_int32(sc->filesize);
	sc->maxprot = (vm_prot_t)swap_int32((uint32_t)sc->maxprot);
	sc->initprot = (vm_prot_t)swap_int32((uint32_t)sc->initprot);
	sc->nsects = swap_int32(sc->nsects);
	sc->flags = swap_int32(sc->flags);
	i = 0;
	while (i < sc->nsects)
		swap_section((struct section *)(sc + 1) + i++);
}
