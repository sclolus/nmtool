/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_dylib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:48:27 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:17:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_dylib(struct dylib	*dylib)
{
	dylib->name.offset = swap_int32(dylib->name.offset);
	dylib->timestamp = swap_int32(dylib->timestamp);
	dylib->current_version = swap_int32(dylib->current_version);
	dylib->compatibility_version = swap_int32(dylib->compatibility_version);
}

void	swap_dylib_command(struct dylib_command *dc)
{
	/* dc->cmd = swap_int32(dc->cmd); */
	/* dc->cmdsize = swap_int32(dc->cmdsize); */
	swap_dylib(&dc->dylib);
}
