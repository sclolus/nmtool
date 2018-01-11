/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fat_host_arch.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:27:24 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 19:36:49 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"
#include "mach-o/arch.h"

struct fat_arch		*get_fat_host_arch(t_ofile *ofile)
{
	struct fat_arch	*archs;
	uint32_t		i;

	i = 0;
	archs = (struct fat_arch*)(ofile->fat_hdr + 1);
	while (i < ofile->fat_hdr->nfat_arch)
	{
		if (archs->cputype == CPU_TYPE_X86
			&& archs->cpusubtype == CPU_SUBTYPE_X86_ARCH1)
			return (archs);
		if (i == 1)
		{
			printf("arch->cputype: %u, arch->cpusubtype: %u\n", archs->cputype, archs->cpusubtype);
		}
		archs++;
		i++;
	}
	return (NULL);
}

struct fat_arch_64	*get_fat_host_arch_64(t_ofile *ofile)
{
	struct fat_arch_64	*archs;
	uint32_t			i;

	i = 0;
	archs = (struct fat_arch_64*)(void*)(ofile->fat_hdr + 1);
	while (i < ofile->fat_hdr->nfat_arch)
	{
		if (archs->cputype == CPU_TYPE_X86
			&& archs->cpusubtype == CPU_SUBTYPE_X86_ARCH1)
			return (archs);
		archs++;
		i++;
	}
	return (NULL);
}
