/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 03:31:30 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 01:17:42 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

//hello you, why are you watching me ?
/* static inline char	get_symbol_char(struct nlist_64 *nlist, char c) */
/* { */
/* 	if (c == 'S') */
/* 	{ */
/* 		if (nlist->n_sect != 0 && nlist->n_sect <= g_ofile->sect_nbr) */
/* 		{ */
/* 			if (g_ofile->special_sects.text_nsect + 1 == nlist->n_sect) */
/* 				return ('T'); */
/* 			else if (g_ofile->special_sects.data_nsect + 1 == nlist->n_sect) */
/* 				return ('D'); */
/* 			else if (g_ofile->special_sects.bss_nsect + 1 == nlist->n_sect) */
/* 				return ('B'); */
/* 		} */
/* 	} */
/* 	if (c == 'U' && nlist->n_value != 0 && nlist->n_sect == NO_SECT && (nlist->n_type & N_EXT)) */
/* 		return ('C'); */
/* 	return (c); */
/* } */

/* static inline void	print_sym_entry(void *file_map, struct symtab_command *sc, struct nlist_64 *nlist) */
/* { */
/* 	const t_sym_char	sym_chars[] = */
/* 	{ */
/* 		{N_UNDF, 'U'}, */
/* 		{N_ABS, 'A'}, */
/* 		{N_SECT, 'S'}, */
/* 		{N_INDR, 'I'}, */
/* 	}; */
/* 	char				printed_char; */
/* 	uint32_t			i; */

/* 	i = 0; */
/* 	while (i < sizeof(sym_chars) / sizeof(*sym_chars)) */
/* 	{ */
/* 		if (((nlist->n_type & N_TYPE)) == sym_chars[i].mask && !(nlist->n_type & N_STAB)) */
/* 		{ */
/* 			printed_char = get_symbol_char(nlist, (char)sym_chars[i].c); */
/* 			printf(printed_char != 'U' ? "%016llx " : "                 ", nlist->n_value); */
/* 			fflush(NULL); */
/* 			ft_putchar(nlist->n_type & N_EXT ? (uint8_t)printed_char : (uint8_t)ft_tolower(printed_char)); */
/* 			ft_putchar(' '); */
/* 			ft_putstr((const char*)file_map + sc->stroff + nlist->n_un.n_strx); */
/* 			printf("\n"); */
/* 			return ; */
/* 		} */
/* 		i++; */
/* 	} */
/* } */

/* static inline void	print_64_string_table(void *file_map, struct symtab_command *sc) */
/* { */
/* 	struct nlist_64	*nlist; */
/* 	uint32_t		i; */

/* 	i = 0; */
/* 	nlist = (struct nlist_64*)(void*)((uint8_t*)file_map + ((struct symtab_command*)sc)->symoff); */
/* 	while (i < sc->nsyms) */
/* 	{ */
/* 		if (!(nlist->n_un.n_strx == 0 || !*((const char*)file_map + sc->stroff + nlist->n_un.n_strx))) */
/* 			print_sym_entry(file_map, sc, nlist); */
/* 		nlist = nlist + 1; */
/* 		i++; */
/* 	} */
/* } */

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

void	nm(void	*file_map, size_t file_size, t_nm_info *nm_info)
{
	struct load_command		*lc;
	struct mach_header_64	*hdr;
	uint32_t				ncmds;

	(void)nm_info;
	hdr = (struct mach_header_64*)file_map;
	lc = (struct load_command*)(void*)((uint8_t*)hdr + sizeof(struct mach_header_64));
	ncmds = 0;
	if (!(g_ofile = parse_ofile(file_map, file_size)))
	{
		ft_error(1, (char*[]){"File not recognized as a valid object file"}, 0);
		return ;
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
