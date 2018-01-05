/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_special_section_nsects.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:13:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 20:30:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	get_special_section_nsects(t_ofile *ofile, struct section *section
									, uint32_t nsect)
{
	if (ft_strequ(section->segname, SEG_TEXT)
		&& ft_strequ(section->sectname, SECT_TEXT))
		ofile->special_sects.text_nsect = nsect;
	else if (ft_strequ(section->segname, SEG_DATA)
		&& ft_strequ(section->sectname, SECT_DATA))
		ofile->special_sects.data_nsect = nsect;
	else if (ft_strequ(section->segname, SEG_DATA)
		&& ft_strequ(section->sectname, SECT_BSS))
		ofile->special_sects.bss_nsect = nsect;
}
