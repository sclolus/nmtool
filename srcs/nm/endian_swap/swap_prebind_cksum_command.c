/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_prebind_cksum_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:49:49 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:50:21 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_prebind_cksum_command(struct prebind_cksum_command *pcc)
{
	pcc->cksum = swap_int32(pcc->cksum);
}
