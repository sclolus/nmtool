/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_version_min_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:57:20 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:58:08 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_version_min_command(struct version_min_command *vmc)
{
	vmc->version = swap_int32(vmc->version);
	vmc->sdk = swap_int32(vmc->sdk);
}
