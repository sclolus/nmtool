/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 03:31:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 13:07:17 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

//hello you, why are you watching me ?

static void	print_64_string_table(struct symtab_command *st, t_nm_info *nm_info)
{
	t_symbol		*symbols;
	uint64_t		symbol_nbr;
	uint32_t		i;

	i = 0;
	if (((struct symtab_command*)st)->symoff + sizeof(struct mach_header_64) >= g_ofile->obj_size)
		return ; // error
	if (!(symbols = select_symbols(nm_info, st, &symbol_nbr)))
		return ; // error
	set_symbols_names(symbols, symbol_nbr, nm_info, st);
	sort_symbols(symbols, symbol_nbr, nm_info);
	print_symbols(symbols, symbol_nbr, nm_info);
}

t_ofile	*g_ofile = NULL;

void	nm(void	*file_map, size_t file_size, t_nm_info *nm_info, char *file_name)
{
	struct mach_header_64	*hdr;
	struct load_command		*lc;
	uint32_t				ncmds;

	(void)nm_info;
	ncmds = 0;
	if (!(g_ofile = parse_ofile(file_map, file_size)))
	{
		ft_error(1, (char*[]){ERR_UNKNOWN_FILE_FORMAT}, 0);
		return ;
	}
	g_ofile->file_name = file_name;
	if (g_ofile->hdr)
	{
		hdr = (struct mach_header_64*)g_ofile->hdr;
		lc = (struct load_command*)(void*)((uint8_t*)g_ofile->hdr + sizeof(struct mach_header));
	}
	else
	{
		hdr = g_ofile->hdr64;
		lc = (struct load_command*)(void*)((uint8_t*)g_ofile->hdr64 + sizeof(struct mach_header_64));
	}
	while (ncmds < hdr->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			print_64_string_table((struct symtab_command*)lc, nm_info);
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		ncmds++;
	}
}
		/* if (lc->cmd == LC_SEGMENT_64) */
		/* 	print_segment_info(((struct segment_command_64*)(void*)lc)); */
