/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_object_count_lc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:55:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 04:57:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ofile.h"

uint32_t	ofile_object_count_lc(t_ofile *ofile, uint32_t cmd)
{
	uint32_t	i;

	i = 0;
	while (ofile_find_n_lc(ofile, cmd, i))
		i++;
	return (i);
}
