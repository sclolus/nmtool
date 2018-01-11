/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_load_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:22:32 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 11:23:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_load_command(struct load_command *lc)
{
	lc->cmd = swap_int32(lc->cmd);
	lc->cmdsize = swap_int32(lc->cmdsize);
}
