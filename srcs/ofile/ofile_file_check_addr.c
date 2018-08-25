/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_file_check_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:04:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:20:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

inline int32_t	ofile_file_check_addr(t_ofile *ofile, void *addr)
{
	if (ofile->vm_addr <= addr
		&& (uint8_t*)ofile->vm_addr + ofile->file_size > (uint8_t*)addr)
		return (0);
	return (-1);
}

inline int32_t	ofile_file_check_addr_size(t_ofile *ofile,
											void *addr,
											uint64_t size)
{
	if (ofile_file_check_addr(ofile, addr) == 0
		&& (size == 0
		|| ofile_file_check_addr(ofile, (uint8_t*)addr + size - 1) == 0))
		return (0);
	return (-1);
}
