/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_symbol_local.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:09:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:09:27 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

bool	is_symbol_local(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (!(is_symbol_extern(sym, nm_info)));
}
