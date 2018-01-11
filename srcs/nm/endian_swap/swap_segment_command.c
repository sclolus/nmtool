/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_segment_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:34:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:46:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_segment_command(struct segment_command *seg)
{
	seg->vmaddr = swap_int32(seg->vmaddr);
	seg->vmsize = swap_int32(seg->vmsize);
	seg->fileoff = swap_int32(seg->fileoff);
	seg->filesize = swap_int32(seg->filesize);
	seg->maxprot = (vm_prot_t)swap_int32((uint32_t)seg->maxprot);
	seg->initprot = (vm_prot_t)swap_int32((uint32_t)seg->initprot);
	seg->nsects = swap_int32(seg->nsects);
	seg->flags = swap_int32(seg->flags);
}

void	swap_segment_command_64(struct segment_command_64 *seg)
{
	seg->vmaddr = swap_int64(seg->vmaddr);
	seg->vmsize = swap_int64(seg->vmsize);
	seg->fileoff = swap_int64(seg->fileoff);
	seg->filesize = swap_int64(seg->filesize);
	seg->maxprot = (vm_prot_t)swap_int32((uint32_t)seg->maxprot);
	seg->initprot = (vm_prot_t)swap_int32((uint32_t)seg->initprot);
	seg->nsects = swap_int32(seg->nsects);
	seg->flags = swap_int32(seg->flags);
}
