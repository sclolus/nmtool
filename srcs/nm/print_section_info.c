/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 07:02:55 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/05 07:18:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_section_info(struct section_64 *sec)
{
	printf("	Section_name: %s, size: %llu, offset: %u\n", sec->sectname, sec->size, sec->offset);
}
