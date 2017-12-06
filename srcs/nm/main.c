/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:02:35 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 17:17:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

int	main(int argc, char **argv)
{
	void		*file_map;
	int			fd;
	struct stat	file_stat;
	t_nm_info	*nm_info;
	uint32_t	i;

	if (!(nm_info = parse_flags(argc, argv)))
		return (EXIT_FAILURE);
	i = 0;
	while (i < nm_info->nbr_files)
	{
		if (-1 == (fd = open(nm_info->files[i], O_RDONLY)))
			return (ft_error(2, (char*[]){"Failed to open(): ", nm_info->files[i]}, EXIT_FAILURE));
		if (-1 == (fstat(fd, &file_stat)))
			return (ft_error(2, (char*[]){"Failed to fstat(): ", nm_info->files[i]}, EXIT_FAILURE));
		if (!(file_map = map_nm_file(fd, (uint64_t)file_stat.st_size)))
			return (EXIT_FAILURE);
		if (nm_info->nbr_files > 1)
			printf("%s:\n", nm_info->files[i]);
		nm(file_map, (uint64_t)file_stat.st_size, nm_info);
		munmap(file_map, (uint64_t)file_stat.st_size);
		close(fd);
		i++;
	}
	return (0);
}
