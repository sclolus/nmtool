/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:01:52 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/05 03:00:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NM_H
# define NM_H

# include "libft.h"
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <unistd.h>
# include <stdlib.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <stdbool.h>

typedef struct	s_special_sections
{
	uint32_t	data_nsect;
	uint32_t	bss_nsect;
	uint32_t	text_nsect;
	uint8_t		pad[4];
}				t_special_sections;

typedef struct	s_symbol
{
	char			*name;
	char			*indr_name;
	struct nlist_64	nl;
}				t_symbol;

typedef struct	s_ofile
{
	uint64_t					obj_size;
	void						*file_map;
	struct mach_header			*hdr;
	struct mach_header_64		*hdr64;
	struct section				**sects;
	struct section_64			**sects64;
	struct segment_command		**segs;
	struct segment_command_64	**segs64;
	t_symbol					*symbols;
	t_special_sections			special_sects;
	uint64_t					sym_nbr;
	int32_t						is_64;
	uint32_t					seg_nbr;
	uint32_t					sect_nbr;
	uint8_t						pad[4];
}				t_ofile;


/*
** Error handling
*/

# define NM_FLAGS "agopruUmj"
# define NM_USAGE "usage: ./ft_nm ["NM_FLAGS"] <input files> " // todo

void	ft_put_nm_usage(void);

/*
** Argument line parsing
*/

# define NM_GETOPT_FLAGS "agopruUmj"
# define DEFAULT_NM_FILE "a.out"

typedef struct	s_flags16
{
	uint16_t	a : 1; // Print all symbol table entries, debuggers' symbols included
	uint16_t	g : 1; // Display only global (external) symbols.
	uint16_t	o : 1; // Prepend file or archive element name to each output line, rather than only once.
	uint16_t	p : 1; // Don't sort : 1; display in symbol-table order.
	uint16_t	r : 1; // Sort in reverse order.
	uint16_t	u : 1; // Display only undefined symbols.
	uint16_t	U : 1; // Don't display undefined symbols
	uint16_t	m : 1; //Display  the  N_SECT  type  symbols  (Mach-O symbols) as (segment_name, section_name) followed by either external or non-external and then the symbol name.
				   // Undefined, common, absolute and indirect symbols get displayed as (undefined), (common), (absolute), and (indirect), respectively.
	uint16_t	j : 1; // Only display symbol names
	uint16_t	bits9 : 1;
	uint16_t	bits10 : 1;
	uint16_t	bits11 : 1;
	uint16_t	bits12 : 1;
	uint16_t	bits13 : 1;
	uint16_t	bits14 : 1;
	uint16_t	bits15 : 1;
}				t_flags16;

typedef union	s_flags
{
	t_flags16	bits;
	uint16_t	flags;
}				t_flags;

typedef struct	s_nm_info
{
	char		**files;
	uint32_t	nbr_files;
	t_flags		flags;
	uint8_t		pad[2];
}				t_nm_info;

t_nm_info	*parse_flags(int argc, char **argv);

/*
** File mapping
*/

void	*map_nm_file(int fd, size_t size);

/*
** Ofile parsing
*/

int32_t	parse_ofile_64(void *file_map, size_t file_size, t_ofile *ofile);
t_ofile	*parse_ofile(void *file_map, size_t file_size);
void	get_special_section_nsects(t_ofile *ofile, struct section *section
								, uint32_t nsect);
int32_t	parse_fat_file(void *file_map
						, size_t file_size
						, t_ofile *ofile);


/*
** nm
*/

typedef struct	s_sym_char
{
	uint8_t	mask;
	uint8_t	c;
}				t_sym_char;

extern t_ofile	*g_ofile;

void		nm(void	*file_map, size_t file_size, t_nm_info *nm_info);
t_symbol	*select_symbols(t_nm_info *nm_info, struct symtab_command *st
							, uint64_t *symbol_nbr);
bool		select_symbol(t_symbol *nl, t_nm_info *nm_info);
void		set_symbols_names(t_symbol *symbols, const uint64_t symbol_nbr
						, const t_nm_info *nm_info, const struct symtab_command *st);

void		print_symbols(t_symbol *symbols, uint64_t sym_nbr, t_nm_info *nm_info);
void		sort_symbols(t_symbol *symbols, const uint64_t symbol_nbr
						, const t_nm_info *nm_info);
int			reverse_compare_syms(const void *a, const void *b);
int			compare_syms(const void *a, const void *b);

/*
** Debug
*/
#include <stdio.h> //

void	print_segment_info(struct segment_command_64 *segc);
void	print_section_info(struct section_64 *sec);
#endif
