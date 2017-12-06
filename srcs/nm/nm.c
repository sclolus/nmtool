/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 03:31:30 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 17:43:12 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

//hello you, why are you watching me ?
static inline char	get_symbol_char(struct nlist_64 *nlist, char c)
{
	if (c == 'S')
	{
		if (nlist->n_sect != 0 && nlist->n_sect <= g_ofile->sect_nbr)
		{
			if (ft_strequ(g_ofile->sects64[nlist->n_sect - 1]->segname, SEG_TEXT)
				&& ft_strequ(g_ofile->sects64[nlist->n_sect - 1]->sectname, SECT_TEXT))
				return ('T');
			else if (ft_strequ(g_ofile->sects64[nlist->n_sect - 1]->segname, SEG_DATA))
			{
				if (ft_strequ(g_ofile->sects64[nlist->n_sect - 1]->sectname, SECT_DATA))
					return ('D');
				else if (ft_strequ(g_ofile->sects64[nlist->n_sect - 1]->sectname, SECT_BSS))
					return ('B');
			}
		}
	}
	if (c == 'U' && nlist->n_sect != 0)
		return ('C');
	return (c);
}

static inline void	print_sym_entry(void *file_map, struct symtab_command *sc, struct nlist_64 *nlist)
{
	const t_sym_char	sym_chars[] =
	{
		{N_UNDF, 'U'},
		{N_ABS, 'A'},
		{N_SECT, 'S'},
		{N_INDR, 'I'},
	};
	char				printed_char;
	uint32_t			i;

	i = 0;
	while (i < sizeof(sym_chars) / sizeof(*sym_chars))
	{
		if (((nlist->n_type & N_TYPE)) == sym_chars[i].mask && !(nlist->n_type & N_STAB))
		{
			printed_char = get_symbol_char(nlist, (char)sym_chars[i].c);
			printf(nlist->n_value ? "%016llx " : "                 ", nlist->n_value);
			fflush(NULL);
			ft_putchar(nlist->n_type & N_EXT ? (uint8_t)printed_char : (uint8_t)ft_tolower(printed_char));
			ft_putchar(' ');
			ft_putstr((const char*)file_map + sc->stroff + nlist->n_un.n_strx);
			printf("\n");
			return ;
		}
		i++;
	}
}

static inline void	print_64_string_table(void *file_map, struct symtab_command *sc)
{
	struct nlist_64	*nlist;
	uint32_t		i;

	i = 0;
	nlist = (struct nlist_64*)(void*)((uint8_t*)file_map + ((struct symtab_command*)sc)->symoff);
	while (i < sc->nsyms)
	{
		if (!(nlist->n_un.n_strx == 0 || !*((const char*)file_map + sc->stroff + nlist->n_un.n_strx)))
			print_sym_entry(file_map, sc, nlist);
		nlist = nlist + 1;
		i++;
	}
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
			print_64_string_table(file_map, (struct symtab_command*)lc);
		lc = (struct load_command*)(void*)((uint8_t*)lc + lc->cmdsize);
		ncmds++;
	}
}
		/* if (lc->cmd == LC_SEGMENT_64) */
		/* 	print_segment_info(((struct segment_command_64*)(void*)lc)); */
