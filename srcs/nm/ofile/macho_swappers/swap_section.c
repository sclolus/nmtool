/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_section.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:00:55 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 02:03:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

void	swap_section(struct section *section)
{
	section->addr = swap_int32(section->addr);
	section->size = swap_int32(section->size);
	section->offset = swap_int32(section->offset);
	section->align = swap_int32(section->align);
	section->reloff = swap_int32(section->reloff);
	section->nreloc = swap_int32(section->nreloc);
	section->flags = swap_int32(section->flags);
}
