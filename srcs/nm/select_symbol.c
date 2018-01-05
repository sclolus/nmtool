/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:02:49 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 03:31:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

/*
** Returns true if a symbol is to be selected as to be printed accordingly
** to the flags, false otherwise
*/

inline bool	select_symbol(t_symbol *sym, t_nm_info *nm_info)
{
	if (nm_info->flags.bits.u)
	{
		if ((sym->nl.n_type == (N_UNDF | N_EXT) && sym->nl.n_value == 0) ||
			sym->nl.n_type == (N_PBUD | N_EXT))
			return (true);
		return (false);
	}
	if (nm_info->flags.bits.U && ((sym->nl.n_type & N_TYPE) == N_UNDF))
		return (false);
	if (nm_info->flags.bits.g && (sym->nl.n_type & N_EXT) == 0)
		return (false);
	if ((sym->nl.n_type & N_STAB) && (nm_info->flags.bits.a == FALSE || nm_info->flags.bits.g == TRUE))
		return (false);
	return (true);
}
