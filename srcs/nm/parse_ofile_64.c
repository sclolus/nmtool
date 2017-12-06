/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ofile_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:16:22 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 15:05:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static inline void	get_seg64_nbr(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			seg_nbr;
	uint32_t			i;

	lc = (struct load_command*)(void*)(ofile->hdr64 + 1);
	seg_nbr = 0;
	i = 0;
	while (i < ofile->hdr64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			seg_nbr++;
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
	ofile->seg_nbr = seg_nbr;
}

static inline void	get_sect64_nbr(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			sect_nbr;
	uint32_t			i;

	lc = (struct load_command*)(void*)(ofile->hdr64 + 1);
	sect_nbr = 0;
	i = 0;
	while (i < ofile->hdr64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			sect_nbr += ((struct segment_command_64*)(void*)lc)->nsects;
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
	ofile->sect_nbr = sect_nbr;
}

static inline void	get_sects64(struct segment_command_64 *sc, t_ofile *ofile
								, uint32_t section_offset)
{
	struct section_64	*section;
	uint32_t			i;

	i = 0;
	section = (struct section_64*)(void*)((uint8_t*)sc + sizeof(*sc));
	while (i < sc->nsects)
	{
		ofile->sects64[section_offset + i] = section;
		section++;
		i++;
	}
}

static inline void	get_segs64(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			seg_nbr;
	uint32_t			i;
	uint32_t			section_offset;

	lc = (struct load_command*)(void*)(ofile->hdr64 + 1);
	seg_nbr = 0;
	section_offset = 0;
	i = 0;
	while (i < ofile->hdr64->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64 && seg_nbr < ofile->seg_nbr)
		{
			ofile->segs64[seg_nbr++] = (struct segment_command_64*)(void*)lc;
			get_sects64((struct segment_command_64*)(void*)lc, ofile, section_offset);
			section_offset += ((struct segment_command_64*)(void*)lc)->nsects;
		}
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		i++;
	}
}

int32_t	parse_ofile_64(void *file_map, size_t file_size, t_ofile *ofile)
{
	struct load_command	*lc;

	(void)file_map;
	(void)file_size;
	lc = (struct load_command*)(void*)(ofile->hdr64 + 1);
	get_seg64_nbr(ofile);
	get_sect64_nbr(ofile);
	if (!(ofile->segs64 = ft_memalloc(sizeof(struct segment_command*) * ofile->seg_nbr)))
		return (-1);
	if (!(ofile->sects64 = ft_memalloc(sizeof(struct section_64*) * ofile->sect_nbr)))
	{
		free(ofile->segs64);
		return (-1);
	}
	get_segs64(ofile);
	return (0);
}
