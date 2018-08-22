/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_poisoner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:11:39 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/22 10:25:56 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

static inline void	fill_buf_with_random_data(uint8_t *buf, uint64_t size)
{
	uint32_t	i;

	i = 0;
	while (i < size)
		buf[i++] = (uint8_t)rand();
}

void	*exec_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	uint8_t				random_data[42];
	void				*member;
	void				*addr;

	if (NULL == (member = poisoner->find(ofile, poisoner, cmd)))
	{
		dprintf(2, "There was no %s to poison\n", poisoner->member_name);
		return (NULL);
	}
	addr = poisoner->get(member);
	addr = map_addr_to_poisoned_zone(ofile, addr);
	if (cmd->action == POISON_ACTION_TRUNCATE)
	{
		printf("Performing truncation of %uth member %s at offset %llu\n", cmd->optional_index,
			poisoner->member_name,
			(uint64_t)((uint8_t *)addr - (uint8_t *)poisoned_zone_vm_addr));
		return (addr);
	}
	fill_buf_with_random_data(random_data, sizeof(random_data));
	printf("Modified value of %uth member %s at offset %llu\n", cmd->optional_index,
		   poisoner->member_name,
		   (uint64_t)((uint8_t *)poisoner->set(addr, random_data) - (uint8_t *)poisoned_zone_vm_addr));
	return (addr);
}