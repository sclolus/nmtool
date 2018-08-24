/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:10:16 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:10:19 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_undefined(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_UNDF)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value == 0);
}
