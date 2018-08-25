/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:38:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 15:02:41 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include "ft_ofile.h"
# include "libft.h"

/*
** Argument line parsing
*/

# define NM_FLAGS "gpruUjxn"
# define NM_GETOPT_FLAGS "gpruUjxn"
# define DEFAULT_NM_FILE "a.out"

typedef struct	s_flags16
{
	uint16_t	g : 1;
	uint16_t	p : 1;
	uint16_t	r : 1;
	uint16_t	u : 1;
	uint16_t	capital_u : 1;
	uint16_t	j : 1;
	uint16_t	x : 1;
	uint16_t	n : 1;
	uint16_t	bits8 : 1;
	uint16_t	bits9 : 1;
	uint16_t	bits10 : 1;
	uint16_t	bits11 : 1;
	uint16_t	bits12 : 1;
	uint16_t	bits13 : 1;
	uint16_t	bits14 : 1;
	uint16_t	bits15 : 1;
}				t_flags16;

typedef union	u_flags
{
	t_flags16	bits;
	uint16_t	flags;
}				t_flags;

typedef struct	s_nm_flags
{
	char		**files;
	uint32_t	nbr_files;
	t_flags		flags;
	uint8_t		pad[2];
}				t_nm_flags;

t_nm_flags		*parse_flags(int argc, char **argv);

# define NO_SECT_FOUND ((uint32_t)-1)

typedef struct	s_nm_process_info
{
	uint32_t					nsects;
	uint32_t					nsegs;
	struct section				**secs;
	struct section_64			**secs_64;
	struct segment_command_64	**segs_64;
	struct segment_command		**segs;

	struct symtab_command		*st_lc;
	struct nlist				*symtab;
	struct nlist_64				*symtab_64;
	uint8_t						*string_table;

	struct dysymtab_command		*dysym_lc;

	uint32_t					text_nsect;
	uint32_t					data_nsect;
	uint32_t					bss_nsect;
	uint8_t						pad[4];
}				t_nm_process_info;

typedef struct	s_symbol
{
	struct nlist_64 sym_entry;
	uint8_t			*string;
	uint32_t		len;
	uint32_t		pad;
}				t_symbol;

int32_t			nm(t_ofile *ofile, t_nm_flags *flags);
int32_t			nm_process_obj(t_ofile *ofile, t_nm_flags *flags);
int32_t			nm_handle_fat(t_ofile *ofile, t_nm_flags *flags);
int32_t			nm_handle_archive(t_ofile *ofile, t_nm_flags *flags);
int32_t			nm_current_arch(t_ofile *ofile, t_nm_flags *flags);

int32_t			init_nm_process_info(t_ofile *ofile,
									t_nm_process_info *nm_info);
void			cleanup_nm_process_info(t_nm_process_info *info);
uint32_t		nm_find_section(t_nm_process_info *nm_info,
										char *seg_name,
										char *sec_name);
uint8_t			*nm_get_string_table_entry(t_ofile *ofile,
													t_nm_process_info *nm_info,
													uint32_t index,
													uint32_t *returned_len);
t_symbol		*nm_get_symbols(t_ofile *ofile, t_nm_process_info *nm_info);

void			nm_sort_symbols(t_symbol *symbols,
										const uint64_t symbol_nbr,
										const t_nm_flags *nm_info);

void			nm_print_symbol(t_ofile *ofile,
										t_symbol *sym,
										t_nm_process_info *nm_info,
										t_nm_flags *flags);

void			print_hexdump_sym(t_symbol *sym,
										t_nm_process_info *nm_info);
void			print_undefined_sym(t_symbol *sym,
										t_nm_process_info *nm_info,
										char c);
void			default_print_sym(t_symbol *sym,
										t_nm_process_info *nm_info,
										char c);

/*
** Symbol Predicates
*/

typedef bool	(*t_f_print_predicate)(t_symbol *sym,
										t_nm_process_info *nm_info);

typedef struct	s_print_symbol_predicate
{
	t_f_print_predicate	predicate;
	uint8_t				c;
	uint8_t				pad[7];
}				t_print_symbol_predicate;

# define SUPPORTED_NM_CHAR_SYMBOL_NBR 17
# define NCHARS_SYMBOLS SUPPORTED_NM_CHAR_SYMBOL_NBR

bool			is_symbol_extern(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_local(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_extern_undefined(t_symbol *sym,
										t_nm_process_info *nm_info);
bool			is_symbol_undefined(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_common(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_extern_absolute(t_symbol *sym,
										t_nm_process_info *nm_info);
bool			is_symbol_absolute(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_extern_text(t_symbol *sym,
									t_nm_process_info *nm_info);
bool			is_symbol_text(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_data(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_extern_data(t_symbol *sym,
									t_nm_process_info *nm_info);
bool			is_symbol_extern_bss(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_bss(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_arbitrary_sect(t_symbol *sym,
									t_nm_process_info *nm_info);
bool			is_symbol_extern_arbitrary_sect(t_symbol *sym,
													t_nm_process_info *nm_info);
bool			is_symbol_indirect(t_symbol *sym, t_nm_process_info *nm_info);
bool			is_symbol_extern_indirect(t_symbol *sym,
										t_nm_process_info *nm_info);
bool			is_symbol_stab(t_symbol *sym, t_nm_process_info *nm_info);

/*
** Error handling
*/

# define NM_USAGE "usage: ./ft_nm [-"NM_FLAGS"] <input files> "
# define NM_BAD_STRING_INDEX "bad string index"

void			ft_put_nm_usage(void);

#endif
