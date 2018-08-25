/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 04:03:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 23:24:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static bool		g_r_flag = 0;

static int		compare_syms(const void *a, const void *b)
{
	int	ret;

	ret = ft_strcmp((char *)((const t_symbol*)a)->string,
					(char *)((const t_symbol*)b)->string);
	if (ret)
		return (g_r_flag ? -ret : ret);
	if (((const t_symbol*)a)->sym_entry.n_value
		< ((const t_symbol*)b)->sym_entry.n_value)
		return (g_r_flag ? 1 : -1);
	else if ((((const t_symbol*)a)->sym_entry.n_value
		> ((const t_symbol*)b)->sym_entry.n_value))
		return (g_r_flag ? -1 : 1);
	else
		return (0);
}

static int		compare_syms_n(const void *a, const void *b)
{
	if (((const t_symbol*)a)->sym_entry.n_value
		< ((const t_symbol*)b)->sym_entry.n_value)
		return (g_r_flag ? 1 : -1);
	else if ((((const t_symbol*)a)->sym_entry.n_value
		> ((const t_symbol*)b)->sym_entry.n_value))
		return (g_r_flag ? -1 : 1);
	if (((const t_symbol*)a)->sym_entry.n_type
		< ((const t_symbol*)b)->sym_entry.n_type)
		return (g_r_flag ? 1 : -1);
	else if ((((const t_symbol*)a)->sym_entry.n_type
		> ((const t_symbol*)b)->sym_entry.n_type))
		return (g_r_flag ? -1 : 1);
	else
		return (compare_syms(a, b));
}

void			nm_sort_symbols(t_symbol *symbols,
								const uint64_t symbol_nbr,
								const t_nm_flags *nm_info)
{
	if (nm_info->flags.bits.p)
		return ;
	if (nm_info->flags.bits.r)
		g_r_flag = 1;
	else
		g_r_flag = 0;
	if (nm_info->flags.bits.n)
		ft_sort((void *)symbols,
			symbol_nbr,
			sizeof(t_symbol),
			&compare_syms_n);
	else
	{
		ft_sort((void*)symbols,
			symbol_nbr,
			sizeof(t_symbol),
			&compare_syms);
	}
}
