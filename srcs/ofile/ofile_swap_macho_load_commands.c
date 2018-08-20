/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ofile_swap_macho_load_commands.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 00:46:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 11:32:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

typedef void	(*t_f_lc_swap_callback)(struct load_command *);

typedef struct	s_lc_swapper
{
	t_f_lc_swap_callback	callback;
	uint32_t				cmd;
	uint32_t				pad;
}				t_lc_swapper;

# define NBR_SUPPORTED_LC 4 /* 48 */
static void	swap_load_command(struct load_command *lc)
{
	static const t_lc_swapper	swappers[NBR_SUPPORTED_LC] = {
		{swap_lc_segment, LC_SEGMENT, 0},
		{swap_lc_symtab, LC_SYMTAB, 0},
		{swap_lc_symseg, LC_SYMSEG, 0},
		{swap_lc_segment_64, LC_SEGMENT_64, 0},
	};
	uint32_t	i;

	i = 0;
	lc->cmd = swap_int32(lc->cmd);
	lc->cmdsize = swap_int32(lc->cmdsize);
	while (i < NBR_SUPPORTED_LC)
	{
		if (lc->cmd == swappers[i].cmd)
		{
			swappers[i].callback(lc);
			return ;
		}
		i++;
	}
}

void	ofile_swap_macho_load_commands(t_ofile *ofile)
{
	uint32_t					i;
	struct mach_header			*hdr;
	struct load_command			*cur_lc;


	i = 0;
	if (ofile->mh)
		hdr = ofile->mh;
	else
		hdr = (struct mach_header *)ofile->mh_64;
	assert(hdr);
	cur_lc = ofile->load_commands;
	while (i < hdr->ncmds)
	{
		if (-1 == ofile_object_check_addr_size(ofile, cur_lc, sizeof(struct load_command))
			|| -1 == ofile_object_check_addr_size(ofile, (uint8_t*)cur_lc, cur_lc->cmdsize))
		{
			dprintf(2, "Object file is malformed, the load commands would go beyond the end of the file\n");
			exit(EXIT_FAILURE);
		}
		swap_load_command(cur_lc);
		cur_lc = (struct load_command *)(void *)((uint8_t*)cur_lc + cur_lc->cmdsize);
		i++;
	}
}
