/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   munmap_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 03:20:01 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 03:21:59 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int	munmap_file(t_ofile *ofile)
{
	return (munmap(ofile->vm_addr, ofile->file_size));
}
