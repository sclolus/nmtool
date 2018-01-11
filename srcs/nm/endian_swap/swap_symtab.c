/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_symtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:38:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 12:03:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline void	swap_nlists(t_ofile *ofile, struct symtab_command *st)
{
	struct nlist	*nlist;
	struct nlist_64	*nlist_64;
	uint64_t		i;

	i = 0;
	nlist = NULL;
	nlist_64 = NULL;
	if (ofile->hdr)
		nlist = (struct nlist*)(void*)((uint8_t*)ofile->hdr + st->symoff);
	else
		nlist_64 = (struct nlist_64*)(void*)((uint8_t*)ofile->hdr64 + st->symoff);
	while (i < st->nsyms)
	{
		if (ofile->hdr)
			swap_nlist(nlist + i);
		else
			swap_nlist_64(nlist_64 + i);
		i++;
	}
}

void				swap_symtab(t_ofile *ofile, struct load_command *lc)
{
	uint32_t			i;
	uint32_t			ncmds;

	i = 0;
	if (ofile->hdr)
		ncmds = ofile->hdr->ncmds;
	else if (ofile->hdr64)
		ncmds = ofile->hdr64->ncmds;
	else
		return ; // possible error ?
	while (i < ofile->hdr->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			swap_nlists(ofile, (struct symtab_command *)lc);
		lc = (struct load_command*)((uint64_t)lc + lc->cmdsize);
		i++;
	}
}
