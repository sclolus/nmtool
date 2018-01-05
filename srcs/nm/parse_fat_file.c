/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fat_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:43:50 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 21:56:07 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int32_t			parse_fat_file(void *file_map
						, size_t file_size
						, t_ofile *ofile)
{
	/* if (FAT_MAGIC == *(uint32_t*)file_map) */
	/* { */
	/* 	ofile->is_64 = 0; */

	/* } */
	/* else if (FAT_MAGIC == *(uint32_t*)file_map) */
	/* { */
	/* 	ofile->is_64 = 1; */
	/* } */
	/* else */
	/* 	return (-1); */
	(void)file_map;
	(void)file_size;
	(void)ofile;
	return (-1);
}
