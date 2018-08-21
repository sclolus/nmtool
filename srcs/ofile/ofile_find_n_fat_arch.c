/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_n_fat_arch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 06:36:25 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 06:39:57 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct fat_arch	*ofile_find_n_fat_arch(t_ofile *ofile, uint32_t narch)
{
	if (ofile->fat_archs == NULL || ofile->fat_header == NULL)
		return (NULL);
	if (ofile->fat_header->nfat_arch <= narch)
		return (NULL);
	return (ofile->fat_archs + narch);
}
