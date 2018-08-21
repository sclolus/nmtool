/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poisoner.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:18:58 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 07:18:29 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POISONER_H
# define POISONER_H
# include "ft_nm.h"
# include "ft_ofile.h"

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <time.h>



typedef struct s_poison_command	t_poison_command;
typedef struct s_poisoner	t_poisoner;
typedef void *(*t_f_poison_finder)(t_ofile *, const t_poisoner *, const t_poison_command *);
typedef void (*t_f_poison_executor)(t_ofile *, const t_poisoner *, const t_poison_command *);
typedef void *(*t_f_poison_getter)(void *);
typedef void *(*t_f_poison_setter)(void *, void *);

typedef struct s_poisoner
{
	t_f_poison_executor	executor;
	t_f_poison_getter	get;
	t_f_poison_setter	set;
	t_f_poison_finder	find;
	char				*member_name;
	uint32_t			cmd;
	uint8_t				__pad[4];
}				t_poisoner;

typedef enum   e_poison_type
{
	LC_POISON = 0,
	FAT_LEVEL_POISON,
	ARCHIVE_LEVEL_POISON,
	SUB_LC_LEVEL_POISON,
	MACHO_LEVEL_POISON,
	SUPPORTED_POISONS_TYPES,
}				t_poison_type;

typedef struct s_poison_command
{
	t_poison_type	type;
	uint32_t		pindex;
	uint32_t		optional_index;
}			   t_poison_command;

typedef struct	s_poison_list
{
	t_poison_command	*poison_commands;
	uint32_t			pnbr;
	uint8_t				__pad[4];
}				t_poison_list;


void	poison(t_ofile *ofile, t_poison_list *plist);
void	poison_lc_symtab(struct load_command *lc, t_ofile *ofile);
void	poison_lc_segment_64(struct load_command *lc, t_ofile *ofile);
void	poison_lc_segment(struct load_command *lc, t_ofile *ofile);

t_poison_list			*generate_poison_list(t_ofile *ofile, uint32_t pnbr);
t_poison_command		generate_poison_command(t_poison_type type, uint32_t **instances_count);
char					*get_poisoned_file_name(char *original_filename, t_poison_list *plist);

void	exec_lc_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	exec_macho_level_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	exec_sub_level_lc_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	exec_fat_level_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);

void	*finder_section_32(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_section_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_lc(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_nlist_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_nlist(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_fat_arch_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_fat_arch(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);
void	*finder_fat_header(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd);

#define OFFSET_OF(type, member) (uint64_t)(&((type *)0)->member)

#define GET_GETTER_NAME(type_name, member) getter_ ## type_name ## _ ## member
#define GET_SETTER_NAME(type_name, member) setter_ ## type_name ## _ ## member
#define PROT_GETTER(type_name, member) void	*GET_GETTER_NAME(type_name, member)(void *data);
#define PROT_SETTER(type_name, member) void	*GET_SETTER_NAME(type_name, member)(void *data, void *value);


#define DEFINE_GETTER(type_name, type, member)							\
	PROT_GETTER(type_name, member)										\
	void	*GET_GETTER_NAME(type_name, member)(void *data)				\
	{																	\
		return ((void *)((uint8_t *)data + OFFSET_OF(type, member)));	\
	}

#define DEFINE_SETTER(type_name, type, member)							\
	PROT_SETTER(type_name, member)										\
	void	*GET_SETTER_NAME(type_name, member)(void *data, void *value) \
	{																	\
		printf("Modified %lu bytes\n", sizeof(((type *)0)->member)); \
		return (memcpy(data, value, sizeof(((type *)0)->member))); \
	}

#define INIT_POISONER(type_name, type, member, cmd_id, executor, finder) {executor, GET_GETTER_NAME(type_name, member), GET_SETTER_NAME(type_name, member), finder, #type_name "->" #member, cmd_id, {0}}

extern const t_poisoner	*poisoners[SUPPORTED_POISONS_TYPES];
extern const uint64_t	poisoners_count_per_type[SUPPORTED_POISONS_TYPES];
extern void				*poisoned_zone_vm_addr;

void	*allocate_poisoned_zone(const t_ofile *ofile);
int		deallocate_poisoned_zone(const t_ofile *ofile);
void	*map_addr_to_poisoned_zone(const t_ofile *ofile, void *addr);


#endif
