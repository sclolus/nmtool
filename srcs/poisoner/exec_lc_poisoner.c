/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lc_poisoner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:18:53 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 03:33:49 by sclolus          ###   ########.fr       */
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

void	exec_lc_poisoner(t_ofile *ofile, const t_poisoner *poisoner)
{
	uint8_t				random_data[42];
	struct load_command *lc;
	void				 *addr;

	if (NULL == (lc = ofile_find_lc(ofile, poisoner->cmd)))
	{
		dprintf(2, "There was no %s to poison\n", poisoner->member_name);
		return ;
	}
	addr = poisoner->get(lc);
	fill_buf_with_random_data(random_data, sizeof(random_data));
	printf("Modified value of member %s at offset %llu\n",
		   poisoner->member_name,
		   (uint64_t)((uint8_t *)poisoner->set(addr, random_data) - (uint8_t *)ofile->vm_addr));
}
