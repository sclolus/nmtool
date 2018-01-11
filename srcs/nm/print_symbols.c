/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 01:00:16 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:58:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline char	get_char_symbol(t_symbol *sym)
{
	char	printed_char;
	uint8_t	type;


	printed_char = '?';
	type = sym->nl.n_type & N_TYPE;
	if (type == N_UNDF)
	{
		if ((sym->nl.n_type & N_EXT) == N_EXT && sym->nl.n_value != 0)
			printed_char = 'C';
		printed_char = 'U';
	}
	else if (type == N_ABS)
		printed_char = 'A';
	else if (type == N_SECT)
	{
		printed_char = 'S';
		if (sym->nl.n_sect != 0 && sym->nl.n_sect <= g_ofile->sect_nbr)
		{
			if (g_ofile->special_sects.text_nsect + 1 == sym->nl.n_sect)
				printed_char = 'T';
			else if (g_ofile->special_sects.data_nsect + 1 == sym->nl.n_sect)
				printed_char = 'D';
			else if (g_ofile->special_sects.bss_nsect + 1 == sym->nl.n_sect)
				printed_char = 'B';
		}
	}
	else if (type == N_INDR)
		printed_char = 'I';
	if (!(sym->nl.n_type & N_EXT))
		printed_char = (char)ft_tolower(printed_char);
	return (printed_char);
}

static inline void	print_symbol(t_symbol *sym, t_nm_info *nm_info)
{
	char	printed_char;

	if (nm_info->flags.bits.o)
		printf("%s: ", g_ofile->file_name);
	printed_char = get_char_symbol(sym);
	if (nm_info->flags.bits.u || nm_info->flags.bits.j)
		printf("%s\n", sym->name);
	else
	{
		printf(printed_char != 'U' ? "%016llx " : "                 ", sym->nl.n_value);
		printf("%c %s\n", printed_char, sym->name);
	}
}

void	print_symbols(t_symbol *symbols, uint64_t sym_nbr, t_nm_info *nm_info)
{
	uint64_t	i;

	i = 0;
	while (i < sym_nbr)
	{
		print_symbol(symbols + i, nm_info);
		i++;
	}
}
