/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_dyld_info_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:00:01 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 09:02:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_dyld_info_command(struct dyld_info_command *dic)
{
	dic->rebase_off = swap_int32(dic->rebase_off);
	dic->rebase_size = swap_int32(dic->rebase_size);
	dic->bind_off = swap_int32(dic->bind_off);
	dic->bind_size = swap_int32(dic->bind_size);
	dic->weak_bind_off = swap_int32(dic->weak_bind_off);
	dic->weak_bind_size = swap_int32(dic->weak_bind_size);
	dic->lazy_bind_off = swap_int32(dic->lazy_bind_off);
	dic->lazy_bind_size = swap_int32(dic->lazy_bind_size);
	dic->export_off = swap_int32(dic->export_off);
	dic->export_size = swap_int32(dic->export_size);
}
