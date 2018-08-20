/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_section_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:04:13 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 02:04:39 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	swap_section_64(struct section_64 *section)
{
	section->addr = swap_int64(section->addr);
	section->size = swap_int64(section->size);
	section->offset = swap_int32(section->offset);
	section->align = swap_int32(section->align);
	section->reloff = swap_int32(section->reloff);
	section->nreloc = swap_int32(section->nreloc);
	section->flags = swap_int32(section->flags);
}
