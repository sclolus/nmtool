/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_print_sym.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 08:58:12 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 09:01:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	default_print_sym(t_symbol *sym, t_nm_process_info *nm_info, char c)
{
	if (nm_info->symtab)
		ft_printf("%08llx %c %s\n", sym->sym_entry.n_value, c
				, (char *)sym->string);
	else
		ft_printf("%016llx %c %s\n", sym->sym_entry.n_value, c
				, (char *)sym->string);
}
