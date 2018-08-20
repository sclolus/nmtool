/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_macho_level_poisoner.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 04:41:27 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 06:44:05 by sclolus          ###   ########.fr       */
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

void	exec_macho_level_poisoner(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	uint8_t				random_data[42];
	struct mach_header	*mh;
	void				*addr;

	(void)cmd;
	if (ofile->mh)
		mh = ofile->mh;
	else if (ofile->mh_64)
		mh = (struct mach_header *)ofile->mh_64;
	else
	{
		dprintf(2, "There was no %s to poison\n", poisoner->member_name);
		return ;
	}
	addr = poisoner->get(mh);
	addr = map_addr_to_poisoned_zone(ofile, addr);
	fill_buf_with_random_data(random_data, sizeof(random_data));
	printf("Modified value of member %s at offset %llu\n",
		   poisoner->member_name,
		   (uint64_t)((uint8_t *)poisoner->set(addr, random_data) - (uint8_t *)poisoned_zone_vm_addr));

}
