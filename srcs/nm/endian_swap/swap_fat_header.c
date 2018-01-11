/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fat_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:01:12 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 14:53:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_fat_arch(struct fat_arch *fat_arch)
{
	fat_arch->cputype = (cpu_type_t)swap_int32((uint32_t)fat_arch->cputype);
	fat_arch->cpusubtype = (cpu_subtype_t)swap_int32(
							(uint32_t)fat_arch->cpusubtype);
	fat_arch->offset = swap_int32(fat_arch->offset);
	fat_arch->size = swap_int32(fat_arch->size);
	fat_arch->align = swap_int32(fat_arch->align);
}

inline void	swap_fat_arch_64(struct fat_arch_64 *fat_arch)
{
	fat_arch->cputype = (cpu_type_t)swap_int32((uint32_t)fat_arch->cputype);
	fat_arch->cpusubtype = (cpu_subtype_t)swap_int32(
							(uint32_t)fat_arch->cpusubtype);
	fat_arch->offset = swap_int64(fat_arch->offset);
	fat_arch->size = swap_int64(fat_arch->size);
	fat_arch->align = swap_int32(fat_arch->align);
}

inline void	swap_fat_header(struct fat_header *hdr)
{
	hdr->magic = swap_int32(hdr->magic);
	hdr->nfat_arch = swap_int32(hdr->nfat_arch);
}
