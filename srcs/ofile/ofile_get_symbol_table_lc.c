/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ofile_symbol_table_lc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:48:49 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 09:08:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct symtab_command	*ofile_get_symbol_table_lc(t_ofile *ofile)
{
	return ((struct symtab_command *)ofile_find_lc(ofile, LC_SYMTAB));
}
