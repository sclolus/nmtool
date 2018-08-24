/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 01:15:19 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/24 04:26:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static inline char	nm_get_symbol_char(t_symbol *sym,
									t_nm_process_info *nm_info)
{
	const static t_print_symbol_predicate	predicates[NCHARS_SYMBOLS] = {
		{is_symbol_extern_undefined, 'U', {0}}, {is_symbol_common, 'C', {0}},
		{is_symbol_extern_data, 'D', {0}}, {is_symbol_extern_text, 'T', {0}},
		{is_symbol_extern_bss, 'B', {0}}, {is_symbol_stab, '-', {0}},
		{is_symbol_extern_arbitrary_sect, 'S', {0}},
		{is_symbol_extern_indirect, 'I', {0}},
		{is_symbol_extern_absolute, 'A', {0}}, {is_symbol_undefined, 'u', {0}},
		{is_symbol_common, 'c', {0}}, {is_symbol_data, 'd', {0}},
		{is_symbol_text, 't', {0}}, {is_symbol_bss, 'b', {0}},
		{is_symbol_arbitrary_sect, 's', {0}}, {is_symbol_indirect, 'i', {0}},
		{is_symbol_absolute, 'a', {0}},
	};
	uint32_t								i;

	i = 0;
	while (i < sizeof(predicates) / sizeof(*predicates))
	{
		if (predicates[i].predicate(sym, nm_info))
			return ((char)predicates[i].c);
		i++;
	}
	return ((char)-1);
}

static inline bool	should_print_symbol(t_symbol *sym,
										t_nm_process_info *nm_info,
										t_nm_flags *flags,
										char c)
{
	if (c == '-' && !flags->flags.bits.a)
		return (false);
	if (flags->flags.bits.g && !is_symbol_extern(sym, nm_info))
		return (false);
	if (flags->flags.bits.u && !(c == 'u' || c == 'U'))
		return (false);
	if (flags->flags.bits.U && (c == 'u' || c == 'U'))
		return (false);
	return (true);
}

void				nm_print_symbol(t_symbol *sym,
					t_nm_process_info *nm_info,
					t_nm_flags *flags)
{
	char	c;

	c = nm_get_symbol_char(sym, nm_info);
	if (!((char)-1 != c))
		c = '?';
	if (!should_print_symbol(sym, nm_info, flags, c))
		return ;
	if (flags->flags.bits.j || flags->flags.bits.u)
		ft_printf("%s\n", (char *)sym->string);
	else if (c == 'u' || c == 'U')
	{
		if (nm_info->symtab)
			ft_printf("         %c %s\n", c
				   , (char *)sym->string);
			else
				ft_printf("                 %c %s\n", c
					   , (char *)sym->string);
	}
	else
	{
		if (nm_info->symtab)
			ft_printf("%08llx %c %s\n", sym->sym_entry.n_value, c
				   , (char *)sym->string);
			else
				ft_printf("%016llx %c %s\n", sym->sym_entry.n_value, c
					   , (char *)sym->string);
	}
}
