/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fvmfile_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:13:59 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:42:33 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_fvmfile_command(struct fvmfile_command *fc)
{
	fc->name.offset = swap_int32(fc->name.offset);
	fc->header_addr = swap_int32(fc->header_addr);
}
