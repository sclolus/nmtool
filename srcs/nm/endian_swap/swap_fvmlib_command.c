/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fvmlib_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:44:02 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:42:20 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_fvmlib_command(struct fvmlib_command *fvmlib)
{
	/* fvmlib->cmd = swap_int32(fvmlib->cmd); */
	/* fvmlib->cmdsize = swap_int32(fvmlib->cmdsize); */
	fvmlib->fvmlib.minor_version = swap_int32(fvmlib->fvmlib.minor_version);
	fvmlib->fvmlib.header_addr = swap_int32(fvmlib->fvmlib.header_addr);
	fvmlib->fvmlib.name.offset = swap_int32(fvmlib->fvmlib.name.offset);
}
