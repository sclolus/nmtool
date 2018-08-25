/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   otool_process_obj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 06:38:03 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 15:17:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int32_t	otool_process_obj_32(t_ofile *ofile, t_otool_info *otool_info)
{
	int32_t			ret;

	ret = otool_print_section(ofile, otool_info, otool_info->text_nsec);
	cleanup_otool_info(otool_info);
	if (ret == -1)
	{
		ft_dprintf(2, "Truncated or malformed object file "
				"(the text section would go past the end of the file)\n");
		return (-1);
	}
	return (0);
}

static int32_t	otool_process_obj_64(t_ofile *ofile, t_otool_info *otool_info)
{
	int32_t			ret;

	ret = otool_print_section_64(ofile, otool_info, otool_info->text_nsec);
	cleanup_otool_info(otool_info);
	if (ret == -1)
	{
		ft_dprintf(2, "Truncated or malformed object file "
			"(the text section would go past the end of the file)\n");
		return (-1);
	}
	return (0);
}

int32_t			otool_process_obj(t_ofile *ofile)
{
	t_otool_info	otool_info;

	init_otool_info(ofile, &otool_info);
	assert(otool_info.secs || otool_info.secs_64);
	if (otool_info.text_nsec == NO_SECT_FOUND)
	{
		ft_dprintf(2, "There is no text section in the mach-o file\n");
		cleanup_otool_info(&otool_info);
		return (-1);
	}
	if (otool_info.secs)
		return (otool_process_obj_32(ofile, &otool_info));
	else
		return (otool_process_obj_64(ofile, &otool_info));
}
