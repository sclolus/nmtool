/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_poisoner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 03:08:53 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/20 06:08:15 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

__attribute__((always_inline)) inline t_poison_command	generate_poison_command(t_poison_type type, uint32_t **instances_count)
{
	uint32_t	p_index = (uint32_t)rand() % ((uint32_t)poisoners_count_per_type[type]);
	uint32_t	instance_index;

	while (!instances_count[type][p_index]) //really bad worse case scenaria
		p_index = (uint32_t)rand() % ((uint32_t)poisoners_count_per_type[type]);
	instance_index = (uint32_t)rand() % instances_count[type][p_index];
//	printf("there is %llu poisoners in this type\n", poisoners_count_per_type[type]);
	return ((t_poison_command){type, p_index, instance_index});
}
