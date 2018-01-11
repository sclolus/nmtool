/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ofile_endiannes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:01:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 06:27:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_ofile_endianness(t_ofile *ofile, void *file_map
								  , const size_t file_size)
{
	if (ofile->hdr)
		swap_mach_header_32(ofile->hdr);
	else if (ofile->hdr64)
		swap_mach_header_64(ofile->hdr64);

}
