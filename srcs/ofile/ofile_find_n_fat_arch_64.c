/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_find_n_fat_arch_64.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 06:38:50 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 06:46:32 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct fat_arch_64	*ofile_find_n_fat_arch_64(t_ofile *ofile, uint32_t narch)
{
	if (ofile->fat_archs_64 == NULL || ofile->fat_header == NULL)
		return (NULL);
	if (ofile->fat_header->nfat_arch <= narch)
		return (NULL);
	return (ofile->fat_archs_64 + narch);
}
