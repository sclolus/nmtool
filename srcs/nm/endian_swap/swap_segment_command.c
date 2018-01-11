/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_segment_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:34:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:17:26 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_segment_command(struct segment_command *seg)
{
	/* seg->cmd = swap_int32(seg->cmd); */
	/* seg->cmdsize = swap_int32(seg->cmdsize); */
	seg->vmaddr = swap_int32(seg->vmaddr);
	seg->vmsize = swap_int32(seg->vmsize);
	seg->fileoff = swap_int32(seg->fileoff);
	seg->filesize = swap_int32(seg->filesize);
	seg->maxprot = swap_int32(seg->maxprot);
	seg->initprot = swap_int32(seg->initprot);
	seg->nsects = swap_int32(seg->nsects);
	seg->flags = swap_int32(seg->flags);
}

void	swap_segment_command_64(struct segment_command_64 *seg)
{
	/* seg->cmd = swap_int32(seg->cmd); */
	/* seg->cmdsize = swap_int32(seg->cmdsize); */
	seg->vmaddr = swap_int64(seg->vmaddr);
	seg->vmsize = swap_int64(seg->vmsize);
	seg->fileoff = swap_int64(seg->fileoff);
	seg->filesize = swap_int64(seg->filesize);
	seg->maxprot = swap_int32(seg->maxprot);
	seg->initprot = swap_int32(seg->initprot);
	seg->nsects = swap_int32(seg->nsects);
	seg->flags = swap_int32(seg->flags);
}
