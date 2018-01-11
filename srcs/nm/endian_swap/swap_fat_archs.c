/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fat_archs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:51:52 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 17:04:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_fat_archs(struct fat_header *fat_hdr)
{
	struct fat_arch		*fat_arch;
	struct fat_arch_64	*fat_arch_64;
	uint32_t			i;

	i = 0;
	fat_arch = (struct fat_arch*)(void*)(fat_hdr + 1);
	fat_arch_64 = (struct fat_arch_64*)(void*)(fat_hdr + 1);
	while (i < fat_hdr->nfat_arch)
	{
		if (fat_hdr->magic == FAT_MAGIC)
			swap_fat_arch(fat_arch + i);
		else
			swap_fat_arch_64(fat_arch_64 + i);
		i++;
	}
}
