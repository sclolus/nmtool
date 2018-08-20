/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_check_object_integrity.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 20:30:08 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 22:52:46 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

typedef int32_t	(*t_f_lc_integrity_check)(t_ofile *ofile, struct load_command *);

typedef struct	s_lc_integrity_check
{
	t_f_lc_integrity_check	callback;
	uint32_t				cmd;
	uint32_t				pad;
}				t_lc_integrity_check;

# define INTEGRITY_NBR_SUPPORTED_LC 3 /* 48 */
static int32_t	check_load_command_integrity(t_ofile *ofile, struct load_command *lc)
{
	static const t_lc_integrity_check	checkers[INTEGRITY_NBR_SUPPORTED_LC] = {
		{check_lc_segment_integrity, LC_SEGMENT, 0},
		{check_lc_segment_64_integrity, LC_SEGMENT_64, 0},
		{check_lc_symtab_integrity, LC_SYMTAB, 0},
	};
	uint32_t	i;

	i = 0;
	while (i < INTEGRITY_NBR_SUPPORTED_LC)
	{
		if (lc->cmd == checkers[i].cmd)
		{
			if (-1 == checkers[i].callback(ofile, lc))
				return (-1);
		}
		i++;
	}
	return (0);
}

int32_t	ofile_check_load_commands_integrity(t_ofile *ofile)
{
	uint32_t					i;
	struct mach_header			*hdr;
	struct load_command			*cur_lc;


	i = 0;
	if (ofile->mh)
		hdr = ofile->mh;
	else
		hdr = (struct mach_header *)ofile->mh_64;
	cur_lc = ofile->load_commands;
	while (i < hdr->ncmds)
	{
		if (-1 == ofile_object_check_addr_size(ofile, cur_lc, sizeof(struct load_command))
			|| -1 == ofile_object_check_addr_size(ofile, (uint8_t*)cur_lc, cur_lc->cmdsize))
		{
			dprintf(2, "Object file is malformed, the load commands would go beyond the end of the file\n");
			return (-1);
		}
		if (-1 == check_load_command_integrity(ofile, cur_lc))
			return (-1);
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc + cur_lc->cmdsize);
		i++;
	}
	return (0);
}

int32_t	ofile_check_object_integrity(t_ofile *ofile)
{
	if (-1 == ofile_check_mach_header_integrity(ofile)
		|| -1 == ofile_check_load_commands_integrity(ofile))
		return (-1);
	return (0);
}
