/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_poisoned_file_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 02:51:08 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/26 15:31:04 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

char	*get_poisoned_file_name(char *original_filename, t_poison_list *plist)
{
	char		*tmp;
	uint32_t	i;

	assert(original_filename && plist->pnbr > 0);
	(void)plist;
	i = 0;
	tmp = ft_strjoin(original_filename, "_poisoned_");
	tmp = ft_strjoin_f(tmp, ft_static_ulltoa((uint64_t)rand()), 0);
	/* while (i < plist->pnbr) */
	/* { */
	/* 	tmp = ft_strjoin_f(tmp, "_", 0); */
	/* 	tmp = ft_strjoin_f(tmp, poisoners */
	/* 					   [plist->poison_commands[i].type] */
	/* 					   [plist->poison_commands[i].pindex].member_name, 0); */
	/* 	tmp = ft_strjoin_f(tmp, "(", 0); */
	/* 	tmp = ft_strjoin_f(tmp, ft_static_ulltoa(plist->poison_commands[i].optional_index), 0); */
	/* 	tmp = ft_strjoin_f(tmp, ")", 0); */
	/* 	i++; */
	/* } */
	return (tmp);
}
