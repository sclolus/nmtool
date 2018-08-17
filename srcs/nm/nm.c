/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 03:23:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int32_t	nm(t_ofile *ofile, t_nm_flags *flags)
{
	t_nm_process_info	nm_info;
	uint32_t			i;
	t_symbol			*symbols;

	(void)flags;
	assert(ofile->ofile_type == OFILE_MACHO);
	if (-1 == init_nm_process_info(ofile, &nm_info))
		exit(EXIT_FAILURE);
	symbols = nm_get_symbols(&nm_info);
	i = 0;
	while (i < nm_info.st_lc->nsyms)
	{
		if (symbols[i].len)
			nm_print_symbol(symbols + i, &nm_info);
		i++;
	}
	return (0);
}
