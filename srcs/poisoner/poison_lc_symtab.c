/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poison_lc_symtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 19:53:51 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/19 20:00:14 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "poisoner.h"

void	poison_lc_symtab(struct load_command *lc, t_ofile *ofile)
{
	struct symtab_command	*sc;

	(void)ofile;
	sc = (struct symtab_command *)lc;
	sc->symoff = (uint32_t)rand();
	sc->nsyms = (uint32_t)rand();
	sc->stroff = (uint32_t)rand();
	sc->strsize = (uint32_t)rand();
}
