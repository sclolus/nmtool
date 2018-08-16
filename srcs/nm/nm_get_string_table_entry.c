/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_get_string_table_entry.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 09:29:09 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 09:51:44 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint8_t	*nm_get_string_table_entry(uint8_t *string_table, uint32_t index, uint32_t *returned_len)
{
	uint32_t	i;

	i = 1;
	if (index == 0)
	{
		*returned_len = 0;
		return ((uint8_t*)"");
	}
	*returned_len = (uint32_t)ft_strlen((char*)(string_table + index));
	return (string_table + index);
}
