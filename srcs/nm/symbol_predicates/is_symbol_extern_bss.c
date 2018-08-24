/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_extern_bss.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:13:36 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:19:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_extern_bss(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->bss_nsect);
}