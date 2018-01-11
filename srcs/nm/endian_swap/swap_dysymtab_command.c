/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_dysymtab_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:35:36 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:47:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_dysymtab_command(struct dysymtab_command *dc)
{
	dc->ilocalsym = swap_int32(dc->ilocalsym);
	dc->nlocalsym = swap_int32(dc->nlocalsym);
	dc->iextdefsym = swap_int32(dc->iextdefsym);
	dc->nextdefsym = swap_int32(dc->nextdefsym);
	dc->iundefsym = swap_int32(dc->iundefsym);
	dc->nundefsym = swap_int32(dc->nundefsym);
	dc->tocoff = swap_int32(dc->tocoff);
	dc->ntoc = swap_int32(dc->ntoc);
	dc->modtaboff = swap_int32(dc->modtaboff);
	dc->nmodtab = swap_int32(dc->nmodtab);
	dc->extrefsymoff = swap_int32(dc->extrefsymoff);
	dc->nextrefsyms = swap_int32(dc->nextrefsyms);
	dc->indirectsymoff = swap_int32(dc->indirectsymoff);
	dc->nindirectsyms = swap_int32(dc->nindirectsyms);
	dc->extreloff = swap_int32(dc->extreloff);
	dc->nextrel = swap_int32(dc->nextrel);
	dc->locreloff = swap_int32(dc->locreloff);
	dc->nlocrel = swap_int32(dc->nlocrel);
}
