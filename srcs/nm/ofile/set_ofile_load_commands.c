/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ofile_load_commands.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:51:19 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/15 22:53:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct load_command	*set_ofile_load_commands(t_ofile *ofile)
{
	if (ofile->mh)
		ofile->load_commands = (struct load_command*)(ofile->mh + 1);
	else if (ofile->mh_64)
		ofile->load_commands = (struct load_command*)(ofile->mh_64 + 1);
	else
		return (NULL);
	return (ofile->load_commands);
}
