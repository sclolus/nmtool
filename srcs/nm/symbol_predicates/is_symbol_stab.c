/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_stab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:16:02 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:16:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_stab(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (((sym->sym_entry.n_type & N_STAB)));
}
