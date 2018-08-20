/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_host_byte_sex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:20:37 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 06:30:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

t_byte_sex	get_host_byte_sex(void)
{
	int32_t	endian;

	endian = ft_get_endianness();
	if (endian == 1)
		return (LITTLE_ENDIAN_BYTE_SEX);
	else if (endian == 0)
		return (BIG_ENDIAN_BYTE_SEX);
	return (UNKNOWN_BYTE_SEX);
}
