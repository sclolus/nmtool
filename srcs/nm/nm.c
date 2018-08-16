/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 04:46:22 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int32_t	nm(t_ofile *ofile)
{
	t_nm_process_info	nm_info;
	uint32_t			i;

	assert(ofile->ofile_type == OFILE_MACHO);
	if (-1 == init_nm_process_info(ofile, &nm_info))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < nm_info.nsects)
	{
		printf("%s:%s\n", nm_info.secs_64[i]->segname, nm_info.secs_64[i]->sectname);
		i++;
	}
	i = 0;
	while (i < nm_info.nsegs)
	{
		printf("Seg_name: %s, vmaddr: %llu, vm_size: %llu\n", nm_info.segs_64[i]->segname, nm_info.segs_64[i]->vmaddr, nm_info.segs_64[i]->vmsize);
		i++;
	}
	printf("Text section index: %u\n", nm_info.text_nsect);
	printf("data section index: %u\n", nm_info.data_nsect);
	printf("bss section index: %u\n", nm_info.bss_nsect);
	return (0);
}
