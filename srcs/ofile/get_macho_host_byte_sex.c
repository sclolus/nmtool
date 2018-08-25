/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_macho_host_byte_sex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 22:05:27 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:11:01 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

static t_byte_sex	get_inverse_byte_sex(t_byte_sex sex)
{
	if (sex == UNKNOWN_BYTE_SEX)
		return (sex);
	if (sex == LITTLE_ENDIAN_BYTE_SEX)
		return (BIG_ENDIAN_BYTE_SEX);
	else
		return (LITTLE_ENDIAN_BYTE_SEX);
}

t_byte_sex			get_macho_byte_sex(struct mach_header *mh)
{
	t_byte_sex	host_sex;

	host_sex = get_host_byte_sex();
	if (host_sex)
		host_sex = LITTLE_ENDIAN_BYTE_SEX;
	else
		host_sex = BIG_ENDIAN_BYTE_SEX;
	if (mh->magic == MH_MAGIC || mh->magic == MH_MAGIC_64)
		return (host_sex);
	else if (mh->magic == MH_CIGAM || mh->magic == MH_CIGAM_64)
		return (get_inverse_byte_sex(host_sex));
	return (UNKNOWN_BYTE_SEX);
}
