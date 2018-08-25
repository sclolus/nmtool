/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   munmap_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 03:20:01 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 11:45:34 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int	munmap_file(t_ofile *ofile)
{
	int	ret;

	free(ofile->file_name);
	ret = munmap(ofile->vm_addr, ofile->file_size);
	if (ret)
		ft_dprintf(2, "Failed to munmap file: %s\n", ofile->file_name);
	free(ofile);
	return (ret);
}
