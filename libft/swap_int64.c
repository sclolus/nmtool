/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_int64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 04:51:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/18 04:05:22 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline uint64_t	swap_int64(const uint64_t data)
{
	return ((((data & 0xff00000000000000ULL) >> 56) |
			((data & 0x00ff000000000000ULL) >> 40) |
			((data & 0x0000ff0000000000ULL) >> 24) |
			((data & 0x000000ff00000000ULL) >> 8) |
			((data & 0x00000000ff000000ULL) << 8) |
			((data & 0x0000000000ff0000ULL) << 24) |
			((data & 0x000000000000ff00ULL) << 40) |
			((data & 0x00000000000000ffULL) << 56)));
}
