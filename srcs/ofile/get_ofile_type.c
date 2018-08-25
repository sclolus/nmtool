/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ofile_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 20:10:35 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/25 13:15:36 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"

typedef bool	(*t_f_is_ofile_type)(t_ofile *ofile);

static bool		is_archive(t_ofile *ofile)
{
	if (ofile->file_size <= sizeof(STATIC_LIB_MAGIC))
		return (false);
	if (!memcmp(ofile->object_addr,
				STATIC_LIB_MAGIC,
				sizeof(STATIC_LIB_MAGIC) - 1))
		return (true);
	return (false);
}

static bool		is_fat(t_ofile *ofile)
{
	struct fat_header	*hdr;

	hdr = ofile->object_addr;
	if (ofile->file_size <= sizeof(hdr->magic))
		return (false);
	return (hdr->magic == FAT_MAGIC || hdr->magic == FAT_CIGAM
			|| hdr->magic == FAT_MAGIC_64 || hdr->magic == FAT_CIGAM_64);
}

static bool		is_macho(t_ofile *ofile)
{
	struct mach_header		*hdr;
	struct mach_header_64	*hdr_64;

	hdr = ofile->object_addr;
	hdr_64 = ofile->object_addr;
	if (ofile->file_size <= sizeof(hdr->magic)
		|| ofile->file_size <= sizeof(hdr_64->magic))
		return (false);
	return (hdr->magic == MH_MAGIC || hdr->magic == MH_CIGAM ||
			hdr_64->magic == MH_MAGIC_64 || hdr_64->magic == MH_CIGAM_64);
}

static bool		is_unknown(t_ofile *ofile)
{
	(void)ofile;
	return (true);
}

const char			*get_ofile_type_name(t_ofile_type type)
{
	static const t_ofile_type	types[SUPPORTED_OFILE_TYPES] = {
		OFILE_ARCHIVE,
		OFILE_FAT,
		OFILE_MACHO,
		OFILE_UNKNOWN,
	};
	static const char			*names[SUPPORTED_OFILE_TYPES] = {
		"Archive",
		"Fat",
		"Macho_File",
		"Unknown",
	};
	uint32_t					i;

	i = 0;
	while (i < SUPPORTED_OFILE_TYPES)
	{
		if (type == types[i])
			return (names[i]);
		i++;
	}
	return (names[SUPPORTED_OFILE_TYPES - 1]);
}


t_ofile_type	get_ofile_type(t_ofile *ofile)
{
	static const t_ofile_type	types[SUPPORTED_OFILE_TYPES] = {
		OFILE_ARCHIVE,
		OFILE_FAT,
		OFILE_MACHO,
		OFILE_UNKNOWN,
	};
	static const t_f_is_ofile_type	callbacks[SUPPORTED_OFILE_TYPES] = {
		&is_archive,
		&is_fat,
		&is_macho,
		&is_unknown,
	};
	uint32_t					i;

	i = 0;
	while (i < SUPPORTED_OFILE_TYPES)
	{
		if (callbacks[i](ofile))
			return (types[i]);
		i++;
	}
	return (OFILE_UNKNOWN);
}
