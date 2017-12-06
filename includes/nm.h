/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:01:52 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/06 17:13:35 by sclolus          ###   ########.fr       */
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

typedef struct	s_special_sections
{
	struct section		*text;
	struct section64	*text64;
	struct section		*data;
	struct section64	*data64;
	struct section		*bss;
	struct section64	*bss64;
	struct section		*common;
	struct section64	*common64;
}				t_special_sections;

typedef struct	s_special_segments
{
	struct segment_command		*data;
	struct segment_command_64	*data64;
	struct segment_command		*text;
	struct segment_command_64	*text64;
	struct segment_command		*pagezero;
	struct segment_command_64	*pagezero64;
}				t_special_segments;

typedef struct	s_ofile
{
	struct mach_header			*hdr;
	struct mach_header_64		*hdr64;
	struct section				**sects;
	struct section_64			**sects64;
	struct segment_command		**segs;
	struct segment_command_64	**segs64;
	t_special_segments			special_segs;
	t_special_sections			special_sects;
	int32_t						is_64;
	uint32_t					seg_nbr;
	uint32_t					sect_nbr;
	uint8_t						pad[4];
}				t_ofile;


/*
** Error handling
*/

# define NM_USAGE "nm: usage: " // todo

void	ft_put_nm_usage(void);

/*
** Argument line parsing
*/

# define NM_FLAGS "agopruUmj"
# define NM_GETOPT_FLAGS "agopruUmj"
# define DEFAULT_NM_FILE "a.out"

typedef struct	s_flags16
{
	uint16_t	a;
	uint16_t	g;
	uint16_t	o;
	uint16_t	p;
	uint16_t	r;
	uint16_t	u;
	uint16_t	U;
	uint16_t	m;
	uint16_t	j;
	uint16_t	bits9;
	uint16_t	bits10;
	uint16_t	bits11;
	uint16_t	bits12;
	uint16_t	bits13;
	uint16_t	bits14;
	uint16_t	bits15;
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
	uint8_t		pad[4];
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

/*
** nm
*/

typedef struct	s_sym_char
{
	uint8_t	mask;
	uint8_t	c;
}				t_sym_char;

extern t_ofile	*g_ofile;

void	nm(void	*file_map, size_t file_size, t_nm_info *nm_info);

/*
** Debug
*/
#include <stdio.h> //

void	print_segment_info(struct segment_command_64 *segc);
void	print_section_info(struct section_64 *sec);
#endif
