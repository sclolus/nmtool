/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 04:05:23 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int32_t	nm(t_ofile *ofile)
{
	uint32_t			nsects;
	uint32_t			nsegs;
	struct section_64	**secs;
	struct segment_command_64	**segs;
	uint32_t			i;

	assert(ofile->ofile_type == OFILE_MACHO);
	if (!(secs = ofile_get_sections_64(ofile, &nsects)))
		dprintf(2, "Could not find the sections\n");
	if (!(segs = ofile_get_segments_64(ofile, &nsegs)))
		dprintf(2, "Could not find the segments\n");
	i = 0;
	while (i < nsects)
	{
		printf("%s:%s\n", secs[i]->segname, secs[i]->sectname);
		i++;
	}
	i = 0;
	while (i < nsegs)
	{
		printf("Seg_name: %s, vmaddr: %llu, vm_size: %llu\n", segs[i]->segname, segs[i]->vmaddr, segs[i]->vmsize);
		i++;
	}
	return (0);
}
