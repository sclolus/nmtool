/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_symbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:03:56 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 01:26:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static void	make_symbol(t_symbol *sym, struct nlist *nl)
{
	sym->nl.n_un.n_strx = nl->n_un.n_strx;
	sym->nl.n_type = nl->n_type;
	sym->nl.n_sect = nl->n_sect;
	sym->nl.n_desc = (uint16_t)nl->n_desc;
	sym->nl.n_value = (uint64_t)nl->n_value;
}

static void	make_symbol_64(t_symbol *sym, struct nlist_64 *nl)
{
	sym->nl = *nl;
}

t_symbol	*select_symbols(t_nm_info *nm_info, struct symtab_command *st, uint64_t *symbol_nbr)
{
	t_symbol		*symbols;
	struct nlist	*nlist;
	struct nlist_64	*nlist_64;
	t_symbol		tmp_sym;
	uint64_t		i;

	i = 0;
	nlist = NULL;
	nlist_64 = NULL;
	*symbol_nbr = 0;
	if (g_ofile->hdr)
		nlist = (struct nlist*)(void*)((uint8_t*)g_ofile->file_map + ((struct symtab_command*)st)->symoff);
	else
		nlist_64 = (struct nlist_64*)(void*)((uint8_t*)g_ofile->file_map + ((struct symtab_command*)st)->symoff);
	if (!(symbols = (t_symbol*)malloc(sizeof(t_symbol) * st->nsyms)))
		return (NULL);
	while (i < st->nsyms)
	{
		if (g_ofile->hdr)
			make_symbol(&tmp_sym, nlist + i);
		else
			make_symbol_64(&tmp_sym, nlist_64 + i);
		if (select_symbol(&tmp_sym, nm_info))
			symbols[(*symbol_nbr)++] = tmp_sym;
		i++;
	}
	return (symbols);
}
