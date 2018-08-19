/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ofile_mh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:46:01 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 11:14:35 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	*set_ofile_mh(t_ofile *ofile)
{
	struct	mach_header	*mh;

	ofile->mh = NULL;
	ofile->mh_64 = NULL;
	if (-1 == ofile_object_check_addr_size(ofile,
										   ofile->object_addr,
										   sizeof(struct mach_header_64)))
		return (NULL);
	if (ofile->object_addr == NULL)
		return (NULL);
	mh = ofile->object_addr;
	if (mh->magic == MH_MAGIC || mh->magic == MH_CIGAM)
		ofile->mh = mh;
	else if (mh->magic == MH_MAGIC_64 || mh->magic == MH_CIGAM_64)
		ofile->mh_64 = (struct mach_header_64 *)mh;
	else
		return (NULL);
	return ((void *)mh);
}
