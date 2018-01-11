/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_routines_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:30:13 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:32:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_routines_command(struct routines_command *rc)
{
	rc->init_address = swap_int32(rc->init_address);
	rc->init_module = swap_int32(rc->init_module);
}

inline void	swap_routines_command_64(struct routines_command_64 *rc)
{
	rc->init_address = swap_int64(rc->init_address);
	rc->init_module = swap_int64(rc->init_module);
}
