/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 11:47:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int32_t	nm_process_obj(t_ofile *ofile, t_nm_flags *flags)
{
	t_nm_process_info	nm_info;
	uint32_t			i;
	t_symbol			*symbols;

	if (-1 == init_nm_process_info(ofile, &nm_info))
		return (0);
	if (NULL == (symbols = nm_get_symbols(ofile, &nm_info)))
		return (-1);
	nm_sort_symbols(symbols, nm_info.st_lc->nsyms, flags);
	i = 0;
	while (i < nm_info.st_lc->nsyms)
		nm_print_symbol(ofile, symbols + i++, &nm_info, flags);
	free(symbols);
	cleanup_nm_process_info(&nm_info);
	return (0);
}

int32_t	nm_handle_archive(t_ofile *ofile, t_nm_flags *flags)
{
	uint64_t		i;
	bool			soft_error;

	i = 0;
	soft_error = 0;
	while (i < ofile->nran)
	{
		if (-1 == ofile_load_narchive_member(ofile, i, &soft_error))
		{
			if (soft_error)
				return (0);
			ft_printf("Failed to load member\n");
			i++;
			continue ;
		}
		ft_printf("\n%s(%s):\n", ofile->file_name
			, ofile->archive_member_header.member_name);
		if (-1 == nm_process_obj(ofile, flags))
			return (-1);
		i++;
	}
	return (0);
}

int32_t	nm(t_ofile *ofile, t_nm_flags *flags)
{
	if (ofile->ofile_type == OFILE_MACHO)
		return (nm_process_obj(ofile, flags));
	else if (ofile->ofile_type == OFILE_FAT)
		return (nm_handle_fat(ofile, flags));
	else if (ofile->ofile_type == OFILE_ARCHIVE)
		return (nm_handle_archive(ofile, flags));
	return (-1);
}
