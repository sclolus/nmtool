/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lc_symtab_integrity.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 21:33:07 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/23 06:20:28 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

int32_t	check_lc_symtab_integrity(t_ofile *ofile, struct load_command *lc)
{
	struct symtab_command	*sc;

	sc = (struct symtab_command *)(void *)lc;
	if (sizeof(struct symtab_command) != sc->cmdsize)
	{
		ft_dprintf(2, "Malformed object (LC_SYMTAB command has incorrect cmdsize\n");
		return (-1);
	}
	if (sc->symoff > ofile->object_size)
	{
		ft_dprintf(2, "truncated or malformed object (symoff field of LC_SYMTAB command extends past the object file\n");
		return (-1);
	}
	if (sc->stroff > ofile->object_size)
	{
		ft_dprintf(2, "truncated or malformed object (stroff field of LC_SYMTAB command extends past the object file\n");
		return (-1);
	}
	if (sc->symoff + sizeof(struct nlist) * sc->nsyms > ofile->object_size)
	{
		ft_dprintf(2, "truncated or malformed object (stroff field plus nsyms field times sizeof(struct nlist) of LC_SYMTAB comand extends past the object file\n");
		return (-1);
	}
	if (sc->stroff + sc->strsize > ofile->object_size)
	{
		ft_dprintf(2, "truncated or malformed object (stroff field plus strsize field of LC_SYMTAB command extends past the end of the file)");
		return (-1);
	}
	return (0);
}
