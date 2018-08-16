/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ofile_dynamic_symbol_table_lc.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 08:57:26 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 09:08:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

struct dysymtab_command	*ofile_get_dynamic_symbol_table_lc(t_ofile *ofile)
{
	return ((struct dysymtab_command *)ofile_find_lc(ofile, LC_DYSYMTAB));
}
