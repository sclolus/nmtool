/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_symbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:25:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 09:52:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

t_symbol	*nm_get_symbols(t_nm_process_info *nm_info)
{
	t_symbol	*symbols;
	uint32_t	i;

	if (NULL == (symbols = malloc(nm_info->st_lc->nsyms * sizeof(t_symbol))))
		return (NULL);
	i = 0;
	while (i < nm_info->st_lc->nsyms)
	{
		if (nm_info->symtab)
			symbols[i].sym_entry = nm_info->symtab[i];
		else
			symbols[i].sym_entry_64 = nm_info->symtab_64[i];
		symbols[i].string = nm_get_string_table_entry(nm_info->string_table
							, symbols[i].sym_entry.n_un.n_strx, &symbols[i].len);
		i++;
	}
	return (symbols);
}
