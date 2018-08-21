/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ofile.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:10:54 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 03:44:30 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OFILE_H
# define FT_OFILE_H

# include <stdbool.h>
# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/nlist.h>
# include <mach-o/stab.h>
# include <mach-o/ranlib.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include "libft.h"
# include <assert.h> // remove this
# include <stdio.h> // rem ove this

# define STATIC_LIB_MAGIC "!<arch>\x0a"
# define LONG_ARCHIVE_NAME_MAGIC "#1/"

typedef uint32_t t_file_type;

typedef enum	e_byte_sex
{
	UNKNOWN_BYTE_SEX = 0,
	LITTLE_ENDIAN_BYTE_SEX,
	BIG_ENDIAN_BYTE_SEX,
}				t_byte_sex;

typedef enum	e_ofile_type
{
	OFILE_UNKNOWN = 0,
	OFILE_ARCHIVE,
	OFILE_FAT,
	OFILE_MACHO,
	SUPPORTED_OFILE_TYPES,
}				t_ofile_type;

typedef struct	s_archive_member_header
{
	uint8_t		*member_name;
	int64_t		name_length;
	uint8_t		*st_time;
	off_t		st_size;
	uid_t		st_uid;
	gid_t		st_gid;
	mode_t		st_mode;
	bool		long_name;
	uint8_t		pad[5];
}				t_member_header;

typedef struct s_ofile
{
	char			*file_name;
	void			*vm_addr;
	uint64_t		file_size;
	t_ofile_type	ofile_type;
	t_file_type		file_type;

	struct fat_header	*fat_header;
	struct fat_arch		*fat_archs;
	struct fat_arch_64	*fat_archs_64;

	uint32_t			narch;
	t_ofile_type		arch_ofile_type; // don't forget to use this
	// put the arch flag later

	void					*archive_start_addr;
	void					*archive_member_header_addr;
	t_member_header			archive_member_header;
	void					*symdef_addr;
	void					*members;
	struct ranlib			*ranlibs;
	struct ranlib_64		*ranlibs_64;
	uint64_t				nran;
	char					*string_table;
	uint64_t				string_table_size;

	/// if this structure referencing an ofile
	void					*object_addr;
	uint64_t				object_size;
	t_byte_sex				obj_byte_sex;
	bool					must_be_swapped;
	uint8_t					pad[3];
	struct mach_header		*mh;
	struct mach_header_64	*mh_64;
	struct load_command		*load_commands;
}				t_ofile;


void				*map_file(char *filename, uint64_t *file_size);
int					munmap_file(t_ofile *ofile);

t_ofile				*get_ofile(char *filename);

t_ofile_type		get_ofile_type(t_ofile *ofile);
const char			*get_ofile_type_name(t_ofile_type type);

struct section				*ofile_find_n_sect(t_ofile *ofile, uint32_t n);
struct section_64			*ofile_find_n_sect_64(t_ofile *ofile, uint32_t n);

uint32_t					get_nsects(t_ofile *ofile);
uint32_t					get_nsects_64(t_ofile *ofile);
uint32_t					ofile_get_nsegs(t_ofile *ofile);
uint32_t					ofile_get_nsegs_64(t_ofile *ofile);

struct section				**ofile_get_sections(t_ofile *ofile, uint32_t *return_nsects);
struct section_64			**ofile_get_sections_64(t_ofile *ofile, uint32_t *return_nsects);
struct segment_command		**ofile_get_segments(t_ofile *ofile, uint32_t *return_nsegs);
struct segment_command_64	**ofile_get_segments_64(t_ofile *ofile, uint32_t *return_nsegs);


/*
** Loading functions of macho obj in the ofile structure
*/

int32_t					load_macho_ofile(t_ofile *ofile, void *object_addr, uint64_t size);
void					*set_ofile_mh(t_ofile *ofile);
struct load_command		*set_ofile_load_commands(t_ofile *ofile);
void					ofile_swap_macho_load_commands(t_ofile *ofile);
void					ofile_swap_macho_hdr(t_ofile *ofile);
struct load_command		*ofile_get_n_lc(t_ofile *ofile, uint32_t n);
struct load_command		*ofile_find_lc(t_ofile *ofile, uint32_t cmd);
struct load_command		*ofile_find_n_lc(t_ofile *ofile, uint32_t cmd, uint32_t n);
uint32_t				ofile_object_count_lc(t_ofile *ofile, uint32_t cmd);
int32_t					ofile_fat_find_arch(t_ofile *ofile,
							cpu_type_t cputype,
							cpu_subtype_t subtype);

struct symtab_command	*ofile_get_symbol_table_lc(t_ofile *ofile);
struct dysymtab_command	*ofile_get_dynamic_symbol_table_lc(t_ofile *ofile);
struct nlist			*ofile_find_n_nlist(t_ofile *ofile, uint32_t n);
struct nlist_64			*ofile_find_n_nlist_64(t_ofile *ofile, uint32_t n);

int32_t					ofile_object_check_addr(t_ofile *ofile, void *addr);
int32_t					ofile_object_check_addr_size(t_ofile *ofile, void *addr, uint64_t size);

/*
** ** Mach-o load command swapper functions
*/

void				swap_lc_segment(struct load_command *lc);
void				swap_lc_segment_64(struct load_command *lc);
void				swap_lc_symtab(struct load_command *lc);
void				swap_lc_symseg(struct load_command *lc);

void				swap_section(struct section *section);
void				swap_section_64(struct section_64 *section);

/*
** Loading functions of the fat data structures in the ofile structure
*/

void				load_fat_ofile(t_ofile *ofile);
void				ofile_swap_fat_hdrs(t_ofile *ofile);
int32_t				ofile_load_narch(t_ofile *ofile, uint32_t narch);
int32_t				ofile_file_check_addr(t_ofile *ofile, void *addr);
int32_t				ofile_file_check_addr_size(t_ofile *ofile, void *addr, uint64_t size);

/*
** Loading functions of the static archive data structures in the ofile structure
*/

void				load_archive_file(t_ofile *ofile);
void				*ofile_archive_get_member_starting_addr(t_ofile *ofile);
int32_t				archive_parse_member_header(t_ofile *ofile);
int32_t				ofile_load_narchive_member(t_ofile *ofile, uint64_t n_member);

/*
** Byte Sex functions
*/

t_byte_sex			get_macho_byte_sex(struct mach_header *mh);
t_byte_sex			get_host_byte_sex(void);

/*
** CPU types
*/

const char	*get_cputype_name(cpu_type_t type);


/*
** Mach-o Integrity checks
*/

int32_t	ofile_check_object_integrity(t_ofile *ofile);
int32_t	ofile_check_mach_header_integrity(t_ofile *ofile);
int32_t	ofile_check_load_commands_integrity(t_ofile *ofile);
int32_t	check_lc_segment_integrity(t_ofile *ofile, struct load_command *lc);
int32_t	check_lc_segment_64_integrity(t_ofile *ofile, struct load_command *lc);
int32_t	check_lc_symtab_integrity(t_ofile *ofile, struct load_command *lc);

#endif
