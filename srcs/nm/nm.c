/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 02:10:05 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 05:53:38 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int32_t	nm_process_obj(t_ofile *ofile, t_nm_flags *flags)
{
	t_nm_process_info	nm_info;
	uint32_t			i;
	t_symbol			*symbols;

//	assert(ofile->ofile_type == OFILE_MACHO);
	if (-1 == init_nm_process_info(ofile, &nm_info))
		exit(EXIT_FAILURE);
	symbols = nm_get_symbols(&nm_info);
	nm_sort_symbols(symbols, nm_info.st_lc->nsyms, flags);
	i = 0;
	while (i < nm_info.st_lc->nsyms)
	{
		if (symbols[i].len)
			nm_print_symbol(symbols + i, &nm_info, flags);
		i++;
	}
	bzero(ofile->vm_addr, ofile->file_size);
	return (0);
}


int32_t	nm(t_ofile *ofile, t_nm_flags *flags)
{
	int32_t	narch_for_arch;
	if (ofile->ofile_type == OFILE_MACHO)
		return (nm_process_obj(ofile, flags));
	else if (ofile->ofile_type == OFILE_FAT)
	{
		if (-1 == (narch_for_arch = ofile_fat_find_arch(ofile, CPU_TYPE_X86_64, CPU_SUBTYPE_X86_64_ALL)))
		{
			assert(0);
		}
		else
		{
			assert(ofile_load_narch(ofile, (uint32_t)narch_for_arch) == 0);
			return (nm_process_obj(ofile, flags));
		}

	}
	else
	{
		assert(0);
	}
	return (0);
}
