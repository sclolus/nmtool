/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 04:47:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/26 15:44:40 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# include <sys/stat.h>
# include <sys/mman.h>
# include <fcntl.h>
# include "ft_ofile.h"
# include "libft.h"

# define NO_SECT_FOUND ((uint32_t)-1)

typedef struct	s_otool_info
{
	uint32_t					nsects;
	uint32_t					nsegs;
	struct section				**secs;
	struct section_64			**secs_64;
	struct segment_command_64	**segs_64;
	struct segment_command		**segs;

	uint32_t					text_nsec;
	uint8_t						pad[4];
}				t_otool_info;

int32_t			otool(t_ofile *ofile);
int32_t			otool_process_obj(t_ofile *ofile);
int32_t			otool_handle_fat(t_ofile *ofile);
int32_t			otool_handle_archive(t_ofile *ofile);
uint32_t		otool_find_section(t_otool_info *otool_info,
							char *seg_name,
							char *sec_name);
int32_t			init_otool_info(t_ofile *ofile,
										t_otool_info *nm_info);
void			cleanup_otool_info(t_otool_info *info);

int32_t			otool_print_section(t_ofile *ofile
								, t_otool_info *otool_info
								, uint32_t nsec);

int32_t			otool_print_section_64(t_ofile *ofile
								, t_otool_info *otool_info
								, uint32_t nsec);
/*
** Error Handling
*/

# define OTOOL_USAGE "./ft_otool <object file>\n"

void			print_otool_usage(void);

#endif
