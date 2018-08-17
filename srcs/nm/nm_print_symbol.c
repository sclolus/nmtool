/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nm_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 01:15:19 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/17 04:11:37 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

typedef bool	(*t_f_print_predicate)(t_symbol *sym,
										   t_nm_process_info *nm_info);

bool	is_symbol_extern(t_symbol *sym, t_nm_process_info *nm_info);
bool	is_symbol_extern(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (!!(sym->sym_entry.n_type & N_EXT));
}

bool	is_symbol_local(t_symbol *sym, t_nm_process_info *nm_info);
bool	is_symbol_local(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (!(is_symbol_extern(sym, nm_info)));
}

bool	is_symbol_extern_undefined(t_symbol *sym, t_nm_process_info *nm_info);
bool	is_symbol_extern_undefined(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_UNDF)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value == 0);
}

bool	is_symbol_undefined(t_symbol *sym, t_nm_process_info *nm_info);
bool	is_symbol_undefined(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_UNDF)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value == 0);
}

bool is_symbol_common(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_common(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_UNDF)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value != 0);
}

bool is_symbol_extern_absolute(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_absolute(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_ABS)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value != 0);
}

bool is_symbol_absolute(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_absolute(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_ABS)
			&& sym->sym_entry.n_sect == NO_SECT
			&& sym->sym_entry.n_value != 0);
}

bool is_symbol_extern_text(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_text(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->text_nsect);
}

bool is_symbol_text(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_text(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->text_nsect);
}

bool is_symbol_data(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_data(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->data_nsect);
}

bool is_symbol_extern_data(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_data(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->data_nsect);
}

bool is_symbol_extern_bss(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_bss(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->bss_nsect);
}

bool is_symbol_bss(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_bss(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 == nm_info->bss_nsect);
}

bool is_symbol_arbitrary_sect(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_arbitrary_sect(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 != nm_info->bss_nsect
			&& sym->sym_entry.n_sect - 1 != nm_info->text_nsect
			&& sym->sym_entry.n_sect - 1 != nm_info->data_nsect);
}

bool is_symbol_extern_arbitrary_sect(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_arbitrary_sect(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_SECT)
			&& sym->sym_entry.n_sect - 1 != nm_info->bss_nsect
			&& sym->sym_entry.n_sect - 1 != nm_info->text_nsect
			&& sym->sym_entry.n_sect - 1 != nm_info->data_nsect);
}

bool is_symbol_indirect(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_indirect(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_INDR));
}

bool is_symbol_extern_indirect(t_symbol *sym, t_nm_process_info *nm_info);
bool is_symbol_extern_indirect(t_symbol *sym, t_nm_process_info *nm_info)
{
	if (!is_symbol_extern(sym, nm_info))
		return (false);
	return (((sym->sym_entry.n_type & N_TYPE) == N_INDR));
}

bool	is_symbol_stab(t_symbol *sym, t_nm_process_info *nm_info);
bool	is_symbol_stab(t_symbol *sym, t_nm_process_info *nm_info)
{
	(void)nm_info;
	return (((sym->sym_entry.n_type & N_STAB)));
}


typedef struct s_print_symbol_predicate
{
	t_f_print_predicate	predicate;
	uint8_t				c;
	uint8_t				pad[7];
}			   t_print_symbol_predicate;

# define SUPPORTED_NM_CHAR_SYMBOL_NBR 17

static inline char	nm_get_symbol_char(t_symbol *sym, t_nm_process_info *nm_info)
{
	const static t_print_symbol_predicate	predicates[SUPPORTED_NM_CHAR_SYMBOL_NBR] = {
		{is_symbol_extern_undefined, 'U', {0}},
		{is_symbol_common, 'C', {0}},
		{is_symbol_extern_data, 'D', {0}},
		{is_symbol_extern_text, 'T', {0}},
		{is_symbol_extern_bss, 'B', {0}},
		{is_symbol_stab, '-', {0}},
		{is_symbol_extern_arbitrary_sect, 'S', {0}},
		{is_symbol_extern_indirect, 'I', {0}},
		{is_symbol_extern_absolute, 'A', {0}},
		{is_symbol_undefined, 'u', {0}},
		{is_symbol_common, 'c', {0}},
		{is_symbol_data, 'd', {0}},
		{is_symbol_text, 't', {0}},
		{is_symbol_bss, 'b', {0}},
		{is_symbol_arbitrary_sect, 's', {0}},
		{is_symbol_indirect, 'i', {0}},
		{is_symbol_absolute, 'a', {0}},
	};
	uint32_t	i;

	i = 0;
	while (i < sizeof(predicates) / sizeof(*predicates))
	{
		if (predicates[i].predicate(sym, nm_info))
			return ((char)predicates[i].c);
		i++;
	}
	return ((char)-1);
}

static inline bool	should_print_symbol(t_symbol *sym, t_nm_process_info *nm_info, t_nm_flags *flags, char c)
{
	if (c == '-' && !flags->flags.bits.a)
		return (false);
	if (flags->flags.bits.g && !is_symbol_extern(sym, nm_info))
		return (false);
	if (flags->flags.bits.u && !(c == 'u' || c == 'U'))
		return (false);
	if (flags->flags.bits.U && (c == 'u' || c == 'U'))
		return (false);
	return (true);
}

void nm_print_symbol(t_symbol *sym, t_nm_process_info *nm_info, t_nm_flags *flags)
{
	char	c;

	assert(nm_info->symtab || nm_info->symtab_64);
	c = nm_get_symbol_char(sym, nm_info);
	assert((char)-1 != c);
	if (!should_print_symbol(sym, nm_info, flags, c))
		return ;
	if (flags->flags.bits.j || flags->flags.bits.u)
		printf("%s\n", (char *)sym->string);
	else if (c == 'u' || c == 'U')
	{
		printf("                 %c %s\n", c
			   , (char *)sym->string);
	}
	else
	{
		printf("%016llx %c %s\n", sym->sym_entry.n_value, c
		   , (char *)sym->string);
	}
}
