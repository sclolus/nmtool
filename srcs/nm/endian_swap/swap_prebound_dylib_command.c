/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_prebound_dylib_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:25:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:26:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_prebound_dylib_command(struct prebound_dylib_command *pdc)
{
	pdc->name.offset = swap_int32(pdc->name.offset);
	pdc->nmodules = swap_int32(pdc->nmodules);
	pdc->linked_modules.offset = swap_int32(pdc->linked_modules.offset);
}
