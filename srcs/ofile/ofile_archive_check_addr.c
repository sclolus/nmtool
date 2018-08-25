/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_archive_check_addr.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 19:59:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 20:18:31 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

inline int32_t	ofile_archive_check_addr(t_ofile *ofile, void *addr)
{
	assert(ofile->archive_start_addr);
	if (addr < ofile->archive_start_addr
		|| addr < ofile->vm_addr
		|| (uint64_t)((uint8_t*)addr - (uint8_t*)ofile->archive_start_addr)
			> ofile->archive_size
		|| (uint64_t)((uint8_t*)addr - (uint8_t*)ofile->vm_addr)
			> ofile->file_size)
		return (-1);
	return (0);
}

inline int32_t	ofile_archive_check_addr_size(t_ofile *ofile,
											void *addr,
											uint64_t size)
{
	if (ofile_file_check_addr_size(ofile, addr, size) == 0
		&& ofile_archive_check_addr(ofile, addr) == 0
		&& ofile_archive_check_addr(ofile, (uint8_t*)addr + size) == 0)
		return (0);
	return (-1);
}
