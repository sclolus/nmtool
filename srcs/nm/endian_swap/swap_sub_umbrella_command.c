/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sub_umbrella_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:23:45 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:47:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_sub_umbrella_command(struct sub_umbrella_command *suc)
{
	suc->sub_umbrella.offset = swap_int32(suc->sub_umbrella.offset);
}
