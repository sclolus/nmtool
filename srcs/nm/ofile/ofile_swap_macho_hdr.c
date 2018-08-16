/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_swap_macho_hdr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 01:50:00 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 01:54:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	ofile_swap_macho_hdr(t_ofile *ofile)
{
	struct mach_header	*mh;

	mh = ofile->mh ? ofile->mh : (struct mach_header *)ofile->mh_64;
	assert(mh);
	mh->cputype = (cpu_type_t)swap_int32((uint32_t)mh->cputype);
	mh->cpusubtype = (cpu_subtype_t)swap_int32((uint32_t)mh->cpusubtype);
	mh->filetype = swap_int32(mh->filetype);
	mh->ncmds = swap_int32(mh->ncmds);
	mh->sizeofcmds = swap_int32(mh->sizeofcmds);
	mh->flags = swap_int32(mh->flags);
}
