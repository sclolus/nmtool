/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_poisoned_file_name.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 02:51:08 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 02:59:43 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

char	*get_poisoned_file_name(char *original_filename, t_poison_list *plist)
{
	char		*tmp;
	uint32_t	i;

	assert(original_filename && plist->pnbr > 0);
	i = 0;
	tmp = ft_strjoin(original_filename, "_poisoned");
	while (i < plist->pnbr)
	{
		tmp = ft_strjoin_f(tmp, "_", 0);
		tmp = ft_strjoin_f(tmp, poisoners
						   [plist->poison_commands[i].type]
						   [plist->poison_commands[i].pindex].member_name, 0);
		tmp = ft_strjoin_f(tmp, "(", 0);
		tmp = ft_strjoin_f(tmp, ft_static_ulltoa(plist->poison_commands[i].optional_index), 0);
		tmp = ft_strjoin_f(tmp, ")", 0);
		i++;
	}
	return (tmp);
}
