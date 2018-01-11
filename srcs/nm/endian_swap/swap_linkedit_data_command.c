/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_linkedit_data_command.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:53:13 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:54:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_linkedit_data_command(struct linkedit_data_command *ldc)
{
	ldc->dataoff = swap_int32(ldc->dataoff);
	ldc->datasize = swap_int32(ldc->datasize);
}
