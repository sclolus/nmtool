/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_nlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:58:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:44:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_nlist(struct nlist *nl)
{
	nl->n_un.n_strx = swap_int32(nl->n_un.n_strx);
	nl->n_desc = (int16_t)swap_int16((uint16_t)nl->n_desc);
	nl->n_value = swap_int32(nl->n_value);
}

inline void	swap_nlist_64(struct nlist_64 *nl)
{
	nl->n_un.n_strx = swap_int32(nl->n_un.n_strx);
	nl->n_desc = swap_int16(nl->n_desc);
	nl->n_value = swap_int64(nl->n_value);
}
