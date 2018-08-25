/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexdump_sym.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 08:53:09 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 12:37:53 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_hexdump_sym(t_symbol *sym,
						t_nm_process_info *nm_info)
{
	if (nm_info->symtab)
		ft_printf("%08x %02x %02x %04x %08x %s\n", sym->sym_entry.n_value,
				sym->sym_entry.n_type,
				sym->sym_entry.n_sect,
				sym->sym_entry.n_desc,
				sym->sym_entry.n_un.n_strx,
				(char *)sym->string);
	else
		ft_printf("%016llx %02x %02x %04x %08x %s\n", sym->sym_entry.n_value,
				sym->sym_entry.n_type,
				sym->sym_entry.n_sect,
				sym->sym_entry.n_desc,
				sym->sym_entry.n_un.n_strx,
				(char *)sym->string);
}
