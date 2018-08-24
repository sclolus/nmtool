/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_extern_text.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:12:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:20:25 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_extern_text(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->text_nsect);
}