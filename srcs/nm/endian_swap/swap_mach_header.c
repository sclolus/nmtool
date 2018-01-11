/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_mach_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:28:47 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 06:35:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	swap_mach_header(struct mach_header *hdr)
{
	hdr->magic = swap_int32(hdr->magic);
	hdr->cputype = swap_int32(hdr->cputype);
	hdr->cpusubtype = swap_int32(hdr->cpusubtype);
	hdr->filetype = swap_int32(hdr->filetype);
	hdr->ncmds = swap_int32(hdr->ncmds);
	hdr->sizeofcmds = swap_int32(hdr->sizeofcmds);
	hdr->flags = swap_int32(hdr->flags);
}

void	swap_mach_header_64(struct mach_header_64 *hdr)
{
	hdr->magic = swap_int32(hdr->magic);
	hdr->cputype = swap_int32(hdr->cputype);
	hdr->cpusubtype = swap_int32(hdr->cpusubtype);
	hdr->filetype = swap_int32(hdr->filetype);
	hdr->ncmds = swap_int32(hdr->ncmds);
	hdr->sizeofcmds = swap_int32(hdr->sizeofcmds);
	hdr->flags = swap_int32(hdr->flags);
	hdr->reserved = swap_int32(hdr->reserved);
}
