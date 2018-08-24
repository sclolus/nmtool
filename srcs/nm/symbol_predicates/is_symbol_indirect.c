/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_indirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:15:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:19:13 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_indirect(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_INDR));
}
