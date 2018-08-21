/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_n_nlist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 03:39:48 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 03:39:48 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct nlist		*ofile_find_n_nlist(t_ofile *ofile, uint32_t n)
{
	struct symtab_command	*sc;

	if (ofile->mh_64 || NULL == ofile->mh)
		return (NULL);
	if (NULL == (sc = ofile_get_symbol_table_lc(ofile)))
		return (NULL);
	if (sc->nsyms <= n)
		return (NULL);
	return ((struct nlist *)(void *)((uint8_t *)ofile->object_addr + sc->symoff) + n);
}
