/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_poison_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 10:08:31 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 10:09:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

void	free_poison_list(t_poison_list *plist)
{
	free(plist); //currently the plist is stored in just one malloc'ed zone, that may change in the futur
}
