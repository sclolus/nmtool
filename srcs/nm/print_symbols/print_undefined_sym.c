/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_undefined_symbol.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 08:56:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 09:00:55 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_undefined_sym(t_symbol *sym,
							t_nm_process_info *nm_info, char c)
{
	if (nm_info->symtab)
		ft_printf("         %c %s\n", c
				, (char *)sym->string);
	else
		ft_printf("                 %c %s\n", c
				, (char *)sym->string);
}
