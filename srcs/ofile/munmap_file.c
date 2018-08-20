/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   munmap_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 03:20:01 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 23:00:50 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int	munmap_file(t_ofile *ofile)
{
	int	ret;
	///leaks there
	free(ofile->file_name);
	ret = munmap(ofile->vm_addr, ofile->file_size);
	free(ofile);
	return (ret);
}
