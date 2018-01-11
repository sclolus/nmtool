/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_encryption_info_command.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:54:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:56:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_encryption_info_command(struct encryption_info_command *eic)
{
	eic->cryptoff = swap_int32(eic->cryptoff);
	eic->cryptsize = swap_int32(eic->cryptsize);
	eic->cryptid = swap_int32(eic->cryptid);
}

inline void	swap_encryption_info_command_64(
						struct encryption_info_command_64 *eic)
{
	eic->cryptoff = swap_int32(eic->cryptoff);
	eic->cryptsize = swap_int32(eic->cryptsize);
	eic->cryptid = swap_int32(eic->cryptid);
}
