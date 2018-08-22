/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisoners_predicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 09:58:04 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 09:59:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

bool	is_poison_cmd_high_level(t_poison_command *cmd)
{
	if (cmd->type == FAT_LEVEL_POISON || cmd->type == ARCHIVE_LEVEL_POISON)
		return (true);
	return (false);
}

bool	is_poison_cmd_low_level(t_poison_command *cmd)
{
	if (is_poison_cmd_high_level(cmd))
		return (false);
	return (true);
}
