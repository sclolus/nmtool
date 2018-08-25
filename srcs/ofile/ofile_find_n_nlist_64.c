/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_n_nlist_64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 03:40:23 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:06:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct nlist_64		*ofile_find_n_nlist_64(t_ofile *ofile, uint32_t n)
{
	struct symtab_command	*sc;

	if (ofile->mh || NULL == ofile->mh_64)
		return (NULL);
	if (NULL == (sc = ofile_get_symbol_table_lc(ofile)))
		return (NULL);
	if (sc->nsyms <= n)
		return (NULL);
	return ((struct nlist_64 *)(void *)((uint8_t *)ofile->object_addr
										+ sc->symoff) + n);
}
