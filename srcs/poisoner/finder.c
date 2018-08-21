/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 02:16:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/21 07:24:18 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "poisoner.h"

void	*finder_section_32(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	return (ofile_find_n_sect(ofile, cmd->optional_index));
}

void	*finder_section_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	return (ofile_find_n_sect_64(ofile, cmd->optional_index));
}

void	*finder_nlist(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	return (ofile_find_n_nlist(ofile, cmd->optional_index));
}

void	*finder_nlist_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	return (ofile_find_n_nlist_64(ofile, cmd->optional_index));
}

void	*finder_lc(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	struct load_command	*lc;

	if (poisoner->cmd)
		lc = ofile_find_n_lc(ofile, poisoner->cmd, cmd->optional_index);
	else
		lc = ofile_get_n_lc(ofile, cmd->optional_index);
	return (lc);
}

void	*finder_fat_arch(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	return (ofile_find_n_fat_arch(ofile, cmd->optional_index));
}

void	*finder_fat_arch_64(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	(void)cmd;
	return (ofile_find_n_fat_arch_64(ofile, cmd->optional_index));
}

void	*finder_fat_header(t_ofile *ofile, const t_poisoner *poisoner, const t_poison_command *cmd)
{
	(void)poisoner;
	(void)cmd;
	return (ofile->fat_header);
}
