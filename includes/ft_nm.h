/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:38:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 04:30:58 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "ft_ofile.h"
#include "libft.h"
#include <stdio.h> // remove this



/*
** Argument line parsing
*/

# define NM_FLAGS "agopruUmj"
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

typedef struct	s_nm_flags
{
	char		**files;
	uint32_t	nbr_files;
	t_flags		flags;
	uint8_t		pad[2];
}				t_nm_flags;

t_nm_flags	*parse_flags(int argc, char **argv);

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

int32_t		nm(t_ofile *ofile, t_nm_flags *flags);

int32_t		init_nm_process_info(t_ofile *ofile, t_nm_process_info *nm_info);
uint32_t	nm_find_section(t_nm_process_info *nm_info,
							char *seg_name,
							char *sec_name);
uint8_t		*nm_get_string_table_entry(uint8_t *string_table, uint32_t index, uint32_t *returned_len);
t_symbol	*nm_get_symbols(t_nm_process_info *nm_info);

void		nm_sort_symbols(t_symbol *symbols, const uint64_t symbol_nbr
						 , const t_nm_flags *nm_info);
void		nm_print_symbol(t_symbol *sym, t_nm_process_info *nm_info, t_nm_flags *flags);


/*
** Error handling
*/

# define NM_USAGE "usage: ./ft_nm ["NM_FLAGS"] <input files> " // todo
# define ERR_UNKNOWN_FILE_FORMAT "The file was not recognized as a valid object file"

void	ft_put_nm_usage(void);

#endif
