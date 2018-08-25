/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_check_mach_header_integrity.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 22:47:29 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:17:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	ofile_check_mach_header_integrity(t_ofile *ofile)
{
	if (ofile->mh)
	{
		if (ofile->mh->sizeofcmds + sizeof(struct mach_header)
			> ofile->object_size
		|| ofile->mh->ncmds * sizeof(struct load_command)
			+ sizeof(struct mach_header) > ofile->object_size)
		{
			ft_dprintf(2, "truncated or malformed object"
				" (load commands extend past the end of the file)\n");
			return (-1);
		}
	}
	else if (ofile->mh_64)
	{
		if (ofile->mh_64->sizeofcmds + sizeof(struct mach_header_64)
			> ofile->object_size
		|| ofile->mh_64->ncmds * sizeof(struct load_command)
			+ sizeof(struct mach_header_64) > ofile->object_size)
		{
			ft_dprintf(2, "truncated or malformed object"
				" (load commands extend past the end of the file)\n");
			return (-1);
		}
	}
	return (0);
}
