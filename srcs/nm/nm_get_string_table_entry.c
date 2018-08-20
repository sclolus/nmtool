/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_string_table_entry.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:29:09 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 00:13:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

# define NM_BAD_STRING_INDEX "bad string index"

uint8_t	*nm_get_string_table_entry(t_nm_process_info *nm_info,
								   uint32_t index,
								   uint32_t *returned_len)
{
	uint32_t	i;

	i = 1;
	*returned_len = 1;
	if (nm_info->st_lc == NULL || nm_info->string_table == NULL)
		return (NULL);
	if (index == 0)
		return ((uint8_t*)" ");
	if (nm_info->st_lc->strsize <= index)
	{
		*returned_len = sizeof(NM_BAD_STRING_INDEX) - 1;
		return ((uint8_t *)NM_BAD_STRING_INDEX);
	}
	*returned_len = (uint32_t)ft_strlen((char*)(nm_info->string_table + index));// protect that
	return (nm_info->string_table + index);
}
