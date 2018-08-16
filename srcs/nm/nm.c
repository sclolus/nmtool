/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 03:00:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int32_t	nm(t_ofile *ofile)
{
	uint32_t			nsects;
	struct section_64	**secs;
	uint32_t			i;

	assert(ofile->ofile_type == OFILE_MACHO);
	if (!(secs = ofile_get_sections_64(ofile, &nsects)))
		dprintf(2, "Could not find the sections\n");
	i = 0;
	while (i < nsects)
	{
		printf("%s:%s\n", secs[i]->segname, secs[i]->sectname);
		i++;
	}
	return (0);
}
