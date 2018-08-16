/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 19:38:34 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 04:47:13 by sclolus          ###   ########.fr       */
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

# define NO_SECT_FOUND ((uint32_t)-1)

typedef struct	s_nm_process_info
{
	uint32_t					nsects;
	uint32_t					nsegs;
	struct section				**secs;
	struct section_64			**secs_64;
	struct segment_command_64	**segs_64;
	struct segment_command		**segs;
	uint32_t					text_nsect;
	uint32_t					data_nsect;
	uint32_t					bss_nsect;
	uint8_t						pad[4];
}				t_nm_process_info;

int32_t		nm(t_ofile *ofile);

int32_t		init_nm_process_info(t_ofile *ofile, t_nm_process_info *nm_info);
uint32_t	nm_find_section(t_nm_process_info *nm_info,
							char *seg_name,
							char *sec_name);

#endif
