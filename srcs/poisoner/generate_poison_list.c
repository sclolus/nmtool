/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_poison_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:10:22 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 03:23:52 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

t_poison_list	*generate_poison_list(uint32_t pnbr)
{
	t_poison_list	*plist;
	uint64_t		alloc_size;
	uint32_t		i;

	alloc_size = sizeof(*plist) + sizeof(t_poison_command) * pnbr;
	if (NULL == (plist = malloc(alloc_size)))
		exit(EXIT_FAILURE);
	bzero(plist, alloc_size);
	plist->pnbr = pnbr;
	plist->poison_commands = (t_poison_command *)(void *)(plist + 1);
	i = 0;
	while (i < pnbr)
	{
		plist->poison_commands[i] = generate_poison_command(LC_POISON);
		i++;
	}
	return (plist);
}
