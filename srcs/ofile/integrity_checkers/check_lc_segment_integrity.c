/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lc_segment_integrity.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:36:43 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:16:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	check_lc_segment_integrity(t_ofile *ofile, struct load_command *lc)
{
	struct segment_command	*sc;

	sc = (struct segment_command *)(void *)lc;
	if (sc->fileoff > ofile->object_size
		|| sc->fileoff + sc->filesize > ofile->object_size)
	{
		ft_dprintf(2, "Truncated or malformed object"
				" (inconsistent filesize or fileoff in LC_SEGMENT)\n");
		return (-1);
	}
	if (sc->nsects * sizeof(struct section)
		+ sizeof(struct segment_command) != lc->cmdsize)
	{
		ft_dprintf(2, "Truncated or malformed object"
		" (inconsistent cmdsize in LC_SEGMENT for the number of sections)\n");
		return (-1);
	}
	return (0);
}
