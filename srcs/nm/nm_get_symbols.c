/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_symbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:25:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 09:20:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static inline void	make_symbol_32(t_symbol *symbol, struct nlist *nl)
{
	symbol->sym_entry.n_un.n_strx = nl->n_un.n_strx;
	symbol->sym_entry.n_type = nl->n_type;
	symbol->sym_entry.n_sect = nl->n_sect;
	symbol->sym_entry.n_desc = (uint16_t)nl->n_desc;
	symbol->sym_entry.n_value = (uint64_t)nl->n_value;
}

static inline void	make_symbol_64(t_symbol *symbol, struct nlist_64 *nl)
{
	symbol->sym_entry = *nl;
}

t_symbol			*nm_get_symbols(t_ofile *ofile, t_nm_process_info *nm_info)
{
	t_symbol	*symbols;
	uint32_t	i;

	if (nm_info->st_lc == NULL
		|| (nm_info->symtab == NULL && nm_info->symtab_64 == NULL))
		return (NULL);
	if (NULL == (symbols = malloc(nm_info->st_lc->nsyms * sizeof(t_symbol))))
		return (NULL);
	if (nm_info->st_lc->strsize)
		nm_info->string_table[nm_info->st_lc->strsize - 1] = 0;
	i = 0;
	while (i < nm_info->st_lc->nsyms)
	{
		if (nm_info->symtab)
			make_symbol_32(symbols + i, nm_info->symtab + i);
		else
			make_symbol_64(symbols + i, nm_info->symtab_64 + i);
		symbols[i].string = nm_get_string_table_entry(ofile, nm_info
				, symbols[i].sym_entry.n_un.n_strx, &symbols[i].len);
		i++;
	}
	return (symbols);
}
