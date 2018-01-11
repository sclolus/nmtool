/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_symbols_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 00:09:37 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:57:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	set_symbols_names(t_symbol *symbols, const uint64_t symbol_nbr
						, const struct symtab_command *st)
{
	uint64_t	i;
	char		*ref_addr;

	i = 0;

	if (g_ofile->hdr)
		ref_addr = (char*)g_ofile->hdr;
	else
		ref_addr = (char*)g_ofile->hdr64;
	while (i < symbol_nbr)
	{
		if ((symbols[i].nl.n_type & N_TYPE) == N_INDR)
		{
			symbols[i].indr_name = ref_addr
			+ (uint64_t)((const struct symtab_command*)st)->stroff
			+ symbols[i].nl.n_value;
		}
		symbols[i].name = ref_addr + (uint64_t)((const struct symtab_command*)st)->stroff + symbols[i].nl.n_un.n_strx;
		i++;
	}

}
