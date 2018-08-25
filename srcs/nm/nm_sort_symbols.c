/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 04:03:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 07:47:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int		reverse_compare_syms(const void *a, const void *b)
{
	int	ret;

	ret = -ft_strcmp((char *)((const t_symbol*)a)->string,
					(char *)((const t_symbol*)b)->string);
	if (ret)
		return (ret);
	if (((const t_symbol*)a)->sym_entry.n_value
		< ((const t_symbol*)b)->sym_entry.n_value)
		return (1);
	else if ((((const t_symbol*)a)->sym_entry.n_value
		> ((const t_symbol*)b)->sym_entry.n_value))
		return (-1);
	else
		return (0);
}

static int		compare_syms(const void *a, const void *b)
{
	int	ret;

	ret = ft_strcmp((char *)((const t_symbol*)a)->string,
					(char *)((const t_symbol*)b)->string);
	if (ret)
		return (ret);
	if (((const t_symbol*)a)->sym_entry.n_value
		< ((const t_symbol*)b)->sym_entry.n_value)
		return (-1);
	else if ((((const t_symbol*)a)->sym_entry.n_value
		> ((const t_symbol*)b)->sym_entry.n_value))
		return (1);
	else
		return (0);
}

static int		compare_syms_n(const void *a, const void *b)
{
	if (((const t_symbol*)a)->sym_entry.n_value
		< ((const t_symbol*)b)->sym_entry.n_value)
		return (-1);
	else if ((((const t_symbol*)a)->sym_entry.n_value
		> ((const t_symbol*)b)->sym_entry.n_value))
		return (1);
	else
		return (compare_syms(a, b));
}

void			nm_sort_symbols(t_symbol *symbols,
								const uint64_t symbol_nbr,
								const t_nm_flags *nm_info)
{
	if (nm_info->flags.bits.p)
		return ;
	else if (nm_info->flags.bits.r)
	{
		qsort((void*)symbols,
			symbol_nbr,
			sizeof(t_symbol),
			&reverse_compare_syms); // change this
	}
	else if (nm_info->flags.bits.n)
		qsort((void *)symbols,
			  symbol_nbr,
			  sizeof(t_symbol),
			  &compare_syms_n);
	else
	{
		qsort((void*)symbols,
			symbol_nbr,
			sizeof(t_symbol),
			&compare_syms); // change this
	}
}
