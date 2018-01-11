/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sub_framework_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:18:33 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:20:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_sub_framework_command(struct sub_framework_command *sfc)
{
	sfc->umbrella.offset = swap_int32(sfc->umbrella.offset);
}
