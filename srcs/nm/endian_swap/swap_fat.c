/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:57:57 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 15:00:47 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_fat(struct fat_header *fat_hdr)
{
	swap_fat_header(fat_hdr);
	swap_fat_archs(fat_hdr);
}
