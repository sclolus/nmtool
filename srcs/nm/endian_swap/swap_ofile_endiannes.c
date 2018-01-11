/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ofile_endiannes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 06:01:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 18:13:05 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

static const struct s_swap_func		g_swap_funcs[] = {
	{(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}},
	{(void (*)(void*))swap_segment_command_64, LC_SEGMENT_64, {0}},
	{(void (*)(void*))swap_symtab_command, LC_SYMTAB, {0}},
	{(void (*)(void*))swap_thread_command, LC_THREAD, {0}},
	{(void (*)(void*))swap_thread_command, LC_UNIXTHREAD, {0}},
	{(void (*)(void*))swap_prebind_cksum_command, LC_PREBIND_CKSUM, {0}},
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
	/* {(void (*)(void*))swap_segment_command, LC_SEGMENT, {0}}, */
};

static inline void	swap_load_commands(struct load_command *lc, const uint32_t ncmds)
{
	uint32_t			i;
	uint32_t			u;

	i = 0;
	while (i < ncmds)
	{
		swap_load_command(lc);
		u = 0;
		while (u < sizeof(g_swap_funcs) / sizeof(struct s_swap_func))
		{
			if (g_swap_funcs[u].cmd == lc->cmd)
			{
				g_swap_funcs[u].swap((void*)lc);
				break ;
			}
			u++;
		}
		lc = (struct load_command*)((uint64_t)lc + lc->cmdsize);
		i++;
	}
}

void				swap_ofile_endianness(t_ofile *ofile)
{
	struct load_command	*lc;
	uint32_t			ncmds;

	if (ofile->hdr)
	{
		swap_mach_header(ofile->hdr);
		lc = (struct load_command *)((uint64_t)ofile->hdr + sizeof(ofile->hdr));
		ncmds = ofile->hdr->ncmds;
	}
	else if (ofile->hdr64)
	{
		swap_mach_header_64(ofile->hdr64);
		ncmds = ofile->hdr64->ncmds;
		lc = (struct load_command *)((uint64_t)ofile->hdr64
									+ sizeof(ofile->hdr64));
	}
	else
		return ;
	swap_load_commands(lc, ncmds);
	swap_symtab(ofile, lc);
}
