/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_entry_point_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:15:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:42:03 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_entry_point_command(struct entry_point_command *epc)
{
	epc->entryoff = swap_int64(epc->entryoff);
	epc->stacksize = swap_int64(epc->stacksize);
}
