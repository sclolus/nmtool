/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_symbols_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 00:09:37 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 01:32:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	set_symbols_names(t_symbol *symbols, const uint64_t symbol_nbr
						  , const t_nm_info *nm_info, const struct symtab_command *st)
{
	uint64_t	i;

	i = 0;

	(void)nm_info; //needed ?
	while (i < symbol_nbr)
	{
		if ((symbols[i].nl.n_type & N_TYPE) == N_INDR)
		{
			symbols[i].indr_name = (char*)g_ofile->file_map + (uint64_t)((const struct symtab_command*)st)->stroff + symbols[i].nl.n_value;
//			printf("Assigned to indr_symbol: %llu indr_name: %s\n", i, symbols[i].indr_name);
		}
		symbols[i].name = (char*)g_ofile->file_map + (uint64_t)((const struct symtab_command*)st)->stroff + symbols[i].nl.n_un.n_strx;
		if (ft_strlen(symbols[i].name))
//			printf("Assigned to symbol: %llu name: %s\n", i, symbols[i].name);
		i++;
	}

}
