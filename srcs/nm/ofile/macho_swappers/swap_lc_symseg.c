/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lc_symseg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 01:44:28 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 01:45:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void		swap_lc_symseg(struct load_command *lc)
{
	struct symseg_command	*sc;

	sc = (struct symseg_command*)lc;
	sc->offset = swap_int32(sc->offset);
	sc->size = swap_int32(sc->size);
}
