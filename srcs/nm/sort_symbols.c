/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_symbols.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 01:17:45 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 02:33:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int		reverse_compare_syms(const void *a, const void *b)
{
	return (-ft_strcmp(((const t_symbol*)a)->name, ((const t_symbol*)b)->name));
}

int		compare_syms(const void *a, const void *b)
{
	int	ret;

	ret = ft_strcmp(((const t_symbol*)a)->name, ((const t_symbol*)b)->name);
	if (ret)
		return (ret);
	if (((const t_symbol*)a)->nl.n_value < ((const t_symbol*)b)->nl.n_value)
		return (-1);
	else if ((((const t_symbol*)a)->nl.n_value > ((const t_symbol*)b)->nl.n_value))
		return (1);
	else
		return (0);
}

void	sort_symbols(t_symbol *symbols, const uint64_t symbol_nbr
					, const t_nm_info *nm_info)
{
	if (nm_info->flags.bits.p)
		return ;
	else if (nm_info->flags.bits.r)
	{
		qsort((void*)symbols, symbol_nbr, sizeof(t_symbol), &reverse_compare_syms); //
	}
	else
	{
		qsort((void*)symbols, symbol_nbr, sizeof(t_symbol), &compare_syms); //
	}
}
