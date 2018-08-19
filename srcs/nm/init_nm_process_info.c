/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nm_process_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 04:15:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 10:35:06 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

inline static void find_common_sections_indexes(t_nm_process_info *nm_info)
{
	nm_info->text_nsect = nm_find_section(nm_info, SEG_TEXT, SECT_TEXT);
	nm_info->data_nsect = nm_find_section(nm_info, SEG_DATA, SECT_DATA);
	nm_info->bss_nsect = nm_find_section(nm_info, SEG_DATA, SECT_BSS);
}

inline static void find_symbol_table(t_nm_process_info *nm_info, t_ofile *ofile)
{
	if (!(nm_info->st_lc = ofile_get_symbol_table_lc(ofile)))
		exit(EXIT_SUCCESS); // should correct this
	nm_info->dysym_lc = ofile_get_dynamic_symbol_table_lc(ofile);
	if (ofile->mh)
	{
		nm_info->symtab = (struct nlist *)(void *)((uint8_t*)ofile->object_addr + nm_info->st_lc->symoff);
		nm_info->string_table = (uint8_t*)((uint8_t*)ofile->object_addr + nm_info->st_lc->stroff);
	}
	else
	{
		nm_info->symtab_64 = (struct nlist_64 *)(void *)((uint8_t*)ofile->object_addr + nm_info->st_lc->symoff);
		nm_info->string_table = (uint8_t*)((uint8_t*)ofile->object_addr + nm_info->st_lc->stroff);
	}
}

int32_t	init_nm_process_info(t_ofile *ofile, t_nm_process_info *nm_info)
{
	ft_bzero(nm_info, sizeof(t_nm_process_info));
	assert(ofile->mh || ofile->mh_64);
	if (ofile->mh)
	{
		if (!(nm_info->secs = ofile_get_sections(ofile, &nm_info->nsects)))
			return (-1); // put error message
		if (!(nm_info->segs = ofile_get_segments(ofile, &nm_info->nsegs)))
			return (-1); // put error message
	}
	else
	{
		if (!(nm_info->secs_64 = ofile_get_sections_64(ofile, &nm_info->nsects)))
			return (-1); // put error message
		if (!(nm_info->segs_64 = ofile_get_segments_64(ofile, &nm_info->nsegs)))
			return (-1); // put error message
	}
	find_common_sections_indexes(nm_info);
	find_symbol_table(nm_info, ofile);
	return (0);
}
