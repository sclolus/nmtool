/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_symtab_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:33:28 by sclolus           #+#    #+#             */
/*   Updated: 2018/01/11 08:35:16 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nm.h"

inline void	swap_symtab_command(struct symtab_command *sc)
{
	sc->symoff = swap_int32(sc->symoff);
	sc->nsyms = swap_int32(sc->nsyms);
	sc->stroff = swap_int32(sc->stroff);
	sc->strsize = swap_int32(sc->strsize);
	// swap symtab maybe ?
}
