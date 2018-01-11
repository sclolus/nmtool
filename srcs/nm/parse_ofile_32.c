/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ofile_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 03:53:57 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:39:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline void	get_seg32_nbr(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			seg_nbr;
	uint32_t			i;

	lc = (struct load_command*)(void*)(ofile->hdr + 1);
	seg_nbr = 0;
	i = 0;
	while (i < ofile->hdr->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			seg_nbr++;
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
	ofile->seg_nbr = seg_nbr;
}

static inline void	get_sect32_nbr(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			sect_nbr;
	uint32_t			i;

	lc = (struct load_command*)(void*)(ofile->hdr + 1);
	sect_nbr = 0;
	i = 0;
	while (i < ofile->hdr->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			sect_nbr += ((struct segment_command*)(void*)lc)->nsects;
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
	ofile->sect_nbr = sect_nbr;
}

static inline void	get_sects32(struct segment_command *sc, t_ofile *ofile
								, uint32_t section_offset)
{
	struct section		*section;
	uint32_t			i;

	i = 0;
	section = (struct section*)(void*)((uint8_t*)sc + sizeof(*sc));
	while (i < sc->nsects)
	{
		ofile->sects[section_offset + i] = section;
		get_special_section_nsects(ofile, (struct section*)section, section_offset + i);
		section++;
		i++;
	}
}

static inline void	get_segs32(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			seg_nbr;
	uint32_t			i;
	uint32_t			section_offset;

	lc = (struct load_command*)(void*)(ofile->hdr + 1);
	seg_nbr = 0;
	section_offset = 0;
	i = 0;
	while (i < ofile->hdr->ncmds)
	{
		if (lc->cmd == LC_SEGMENT && seg_nbr < ofile->seg_nbr)
		{
			ofile->segs[seg_nbr++] = (struct segment_command*)(void*)lc;
			get_sects32((struct segment_command*)(void*)lc, ofile, section_offset);
			section_offset += ((struct segment_command*)(void*)lc)->nsects;
		}
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
}

int32_t	parse_ofile_32(t_ofile *ofile)
{
	struct load_command	*lc;

	lc = (struct load_command*)(void*)(ofile->hdr + 1);
	get_seg32_nbr(ofile);
	get_sect32_nbr(ofile);
	if (!(ofile->segs = ft_memalloc(sizeof(struct segment_command*) * ofile->seg_nbr)))
		return (-1);
	if (!(ofile->sects = ft_memalloc(sizeof(struct section*) * ofile->sect_nbr)))
	{
		free(ofile->segs);
		return (-1);
	}
	get_segs32(ofile);
	return (0);
}
