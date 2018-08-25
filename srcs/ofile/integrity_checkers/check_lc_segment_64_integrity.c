/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lc_segment_64_integrity.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:46:29 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:14:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	check_lc_segment_64_integrity(t_ofile *ofile, struct load_command *lc)
{
	struct segment_command_64	*sc;

	sc = (struct segment_command_64 *)(void *)lc;
	if (sc->fileoff > ofile->object_size
		|| sc->fileoff + sc->filesize > ofile->object_size)
	{
		ft_dprintf(2, "Truncated or malformed object"
				" (inconsistent filesize or fileoff in LC_SEGMENT_64)\n");
		return (-1);
	}
	if (sc->nsects * sizeof(struct section_64)
		+ sizeof(struct segment_command_64) != lc->cmdsize)
	{
		ft_dprintf(2, "Truncated or malformed object"
	" (inconsistent cmdsize in LC_SEGMENT_64 for the number of sections)\n");
		return (-1);
	}
	return (0);
}
