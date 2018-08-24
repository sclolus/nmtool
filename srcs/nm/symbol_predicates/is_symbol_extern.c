/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_extern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:06:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:06:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_extern(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (!!(sym->sym_entry.n_type & N_EXT));
}
