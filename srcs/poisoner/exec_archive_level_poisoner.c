/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_archive_level_poisoner.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:17:27 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 08:18:27 by sclolus          ###   ########.fr       */
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

void	exec_archive_level_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	uint8_t				random_data[42];
	void				*member;
	void				*addr;

	if (NULL == (member = poisoner->find(ofile, poisoner, cmd)))
	{
		dprintf(2, "There was no %s to poison\n", poisoner->member_name);
		return ;
	}
	addr = poisoner->get(member);
	addr = map_addr_to_poisoned_zone(ofile, addr);
	fill_buf_with_random_data(random_data, sizeof(random_data));
	printf("Modified value of %uth member %s at offset %llu\n", cmd->optional_index,
		   poisoner->member_name,
		   (uint64_t)((uint8_t *)poisoner->set(addr, random_data) - (uint8_t *)poisoned_zone_vm_addr));
}
