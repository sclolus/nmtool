/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:51:15 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 16:41:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int32_t			otool(t_ofile *ofile)
{
	if (ofile->ofile_type == OFILE_MACHO)
	{
		ft_printf("%s:\n", ofile->file_name);
		return (otool_process_obj(ofile));
	}
	else if (ofile->ofile_type == OFILE_FAT)
	{
		return (otool_handle_fat(ofile));
	}
	else if (ofile->ofile_type == OFILE_ARCHIVE)
	{
		ft_printf("Archive : %s\n", ofile->file_name);
		return (otool_handle_archive(ofile));
	}
	return (-1);
}
