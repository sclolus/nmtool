/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_segment_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 07:03:06 by sclolus           #+#    #+#             */
/*   Updated: 2017/12/05 07:37:11 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

void	print_segment_info(struct segment_command_64 *segc)
{
	static uint32_t		section_number = 1;
	uint32_t			i;
	struct section_64	*section;

	i = 0;
	printf("Segment_name: %s, nsects: %u, fileoffset: %llu\n", segc->segname, segc->nsects, segc->fileoff);
	section = (struct section_64*)(segc + 1);
	while (i < segc->nsects)
	{
//		print_section_info();
		printf("section number: %u", section_number++);
		print_section_info(section);
		section++;
		i++;
	}
}
