/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:30:26 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 03:00:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

t_nm_info	*parse_flags(int argc, char **argv)
{
	static t_nm_info	nm_info;
	char				parsed_opt;

	while ((parsed_opt = (char)ft_getopt(argc, argv, NM_GETOPT_FLAGS)) != -1)
	{
		if (parsed_opt == GETOPT_ERR_CHAR)
		{
			ft_put_nm_usage();
			return (NULL);
		}
		nm_info.flags.flags |= 1U << (int)(ft_strchr(NM_FLAGS, parsed_opt)
										- NM_FLAGS);
	}
	if (g_optind < argc)
	{
		nm_info.files = argv + g_optind;
		nm_info.nbr_files = (uint32_t)(argc - g_optind);
	}
	if (!nm_info.nbr_files)
	{
		nm_info.nbr_files = 1;
		if (!(nm_info.files = malloc(sizeof(char *))))
			return (NULL);
		nm_info.files[0] = DEFAULT_NM_FILE;
	}
	return (&nm_info);
}
