/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_get_nmembers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:30:02 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 11:40:09 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static bool		ran_off_already_in_ranlibs(t_ofile *ofile,
										   struct ranlib *ranlib,
										   uint64_t index)
{
	uint64_t	i;

	i = 0;
	assert(ofile->ranlibs && index < ofile->nran);
	while (i < index)
	{
		if (ofile->ranlibs[i].ran_off == ranlib->ran_off)
			return (true);
		i++;
	}
	return (false);
}


static bool		ran_off_already_in_ranlibs_64(t_ofile *ofile,
										   struct ranlib_64 *ranlib,
										   uint64_t index)
{
	uint64_t	i;

	i = 0;
	assert(ofile->ranlibs_64 && index < ofile->nran);
	while (i < index)
	{
		if (ofile->ranlibs_64[i].ran_off == ranlib->ran_off)
			return (true);
		i++;
	}
	return (false);
}

static uint64_t	ofile_get_nmembers_32(t_ofile *ofile)
{
	uint64_t		nmembers;
	uint64_t		i;

	nmembers = ofile->nran;
	i = 0;
	while (i < ofile->nran)
	{
		if (ran_off_already_in_ranlibs(ofile, ofile->ranlibs + i, i))
			nmembers--;
		i++;
	}
	return (nmembers);
}

static uint64_t	ofile_get_nmembers_64(t_ofile *ofile)
{
	uint64_t		nmembers;
	uint64_t		i;

	nmembers = ofile->nran;
	i = 0;
	while (i < ofile->nran)
	{
		if (ran_off_already_in_ranlibs_64(ofile, ofile->ranlibs_64 + i, i))
			nmembers--;
		i++;
	}
	return (nmembers);
}

uint64_t		ofile_get_nmembers(t_ofile *ofile)
{
	assert(ofile->ranlibs || ofile->ranlibs_64);
	if (ofile->ranlibs)
		return (ofile_get_nmembers_32(ofile));
	else
		return (ofile_get_nmembers_64(ofile));
}
