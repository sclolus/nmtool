/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:01:52 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 19:32:19 by sclolus          ###   ########.fr       */
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
# include <mach-o/fat.h>
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
	char						*file_name;
	struct fat_header			*fat_hdr;
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
# define ERR_UNKNOWN_FILE_FORMAT "The file not recognized as a valid object file"

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

int32_t	parse_ofile_64(t_ofile *ofile);
int32_t	parse_ofile_32(t_ofile *ofile);
t_ofile	*parse_ofile(void *file_map, size_t file_size);
int32_t	parse_macho_header(void *file_map
								, size_t file_size
								, t_ofile *ofile);
void	get_special_section_nsects(t_ofile *ofile, struct section *section
								, uint32_t nsect);
int32_t	parse_fat_file(void *file_map
						, size_t file_size
						, t_ofile *ofile);
int32_t	parse_fat_file_32(size_t file_size
						, t_ofile *ofile);
int32_t	parse_fat_file_64(size_t file_size
						, t_ofile *ofile);

struct fat_arch	*get_fat_host_arch(t_ofile *ofile);
struct fat_arch_64	*get_fat_host_arch_64(t_ofile *ofile);

/*
** Endianness handling
*/

struct s_swap_func
{
	void		(*swap)(void*);
	uint32_t	cmd;
	uint8_t		pad[4];
};

void	swap_ofile_endianness(t_ofile *ofile);
void	swap_mach_header(struct mach_header *hdr);
void	swap_mach_header_64(struct mach_header_64 *hdr);
void	swap_fat(struct fat_header *fat_hdr);
void	swap_fat_arch(struct fat_arch *fat_arch);
void	swap_fat_arch_64(struct fat_arch_64 *fat_arch);
void	swap_fat_archs(struct fat_header *fat_hdr);
void	swap_fat_header(struct fat_header *hdr);
void	swap_load_command(struct load_command *lc);
void	swap_segment_command(struct segment_command *seg);
void	swap_segment_command_64(struct segment_command_64 *seg);
void	swap_fvmlib_command(struct fvmlib_command *fvmlib);
void	swap_dylib_command(struct dylib_command *dc);
void	swap_dylib(struct dylib	*dylib);
void	swap_sub_framework_command(struct sub_framework_command *sfc);
void	swap_sub_client_command(struct sub_client_command *scc);
void	swap_sub_umbrella_command(struct sub_umbrella_command *suc);
void	swap_sub_library_command(struct sub_library_command *slc);
void	swap_prebound_dylib_command(struct prebound_dylib_command *pdc);
void	swap_dylinker_command(struct dylinker_command *dc);
void	swap_thread_command(struct thread_command *tc);
void	swap_routines_command(struct routines_command *rc);
void	swap_routines_command_64(struct routines_command_64 *rc);
void	swap_symtab_command(struct symtab_command *sc);
void	swap_dysymtab_command(struct dysymtab_command *dc);
//void	swap_dylib_table_of_contents(struct dylib_table_of_contents *dtoc); to be implemented
//all load_commands are too be supported, but I'm too lazy to do every data structure
void	swap_prebind_cksum_command(struct prebind_cksum_command *pcc);
void	swap_uuid_command(struct uuid_command *uc);
void	swap_rpath_command(struct rpath_command *rc);
void	swap_linkedit_data_command(struct linkedit_data_command *ldc);
void	swap_encryption_info_command(struct encryption_info_command *eic);
void	swap_encryption_info_command_64(
				struct encryption_info_command_64 *eic);
void	swap_version_min_command(struct version_min_command *vmc);
void	swap_dyld_info_command(struct dyld_info_command *dic);
void	swap_linker_option_command(struct linker_option_command *loc);
void	swap_fvmfile_command(struct fvmfile_command *fc);
void	swap_entry_point_command(struct entry_point_command *epc);
void	swap_source_version_command(struct source_version_command *svc);
void	swap_nlist_64(struct nlist_64 *nl);
void	swap_nlist(struct nlist *nl);
void	swap_symtab(t_ofile *ofile, struct load_command *lc);

/*
** nm
*/

typedef struct	s_sym_char
{
	uint8_t	mask;
	uint8_t	c;
}				t_sym_char;

extern t_ofile	*g_ofile;

void		nm(void	*file_map, size_t file_size, t_nm_info *nm_info, char *file_name);
t_symbol	*select_symbols(t_nm_info *nm_info, struct symtab_command *st
							, uint64_t *symbol_nbr);
bool		select_symbol(t_symbol *nl, t_nm_info *nm_info);
void		set_symbols_names(t_symbol *symbols, const uint64_t symbol_nbr
						, const struct symtab_command *st);

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
