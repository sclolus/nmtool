/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_source_version_command.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:16:44 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 10:46:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_source_version_command(struct source_version_command *svc)
{
	svc->version = swap_int64(svc->version);
}
