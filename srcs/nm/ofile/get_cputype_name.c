/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cputype_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 23:58:14 by sclolus           #+#    #+#             */
/*   Updated: 2018/08/16 00:14:00 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ofile.h"
#include "mach/machine.h"

const char	*get_cputype_name(cpu_type_t type)
{
	static const char	*names[15] = {
		"any",
		"vax",
		"MC680x0",
		"i386",
		"x86",
		"x86_64",
		"MC98000",
		"HPPA",
		"arm",
		"arm64",
		"MC88000",
		"SPARC",
		"i860",
		"PowerPc",
		"PowerPc46",
	};
	static const cpu_type_t	types[15] = {
		CPU_TYPE_ANY,
		CPU_TYPE_VAX,
		CPU_TYPE_MC680x0,
		CPU_TYPE_I386,
		CPU_TYPE_X86,
		CPU_TYPE_X86_64,
		CPU_TYPE_MC98000,
		CPU_TYPE_HPPA,
		CPU_TYPE_ARM,
		CPU_TYPE_ARM64,
		CPU_TYPE_MC88000,
		CPU_TYPE_SPARC,
		CPU_TYPE_I860,
		CPU_TYPE_POWERPC,
		CPU_TYPE_POWERPC64,
	};
	uint32_t	i;

	i = 0;
	while (i < sizeof(types) / sizeof(*types))
	{
		if (type == types[i])
			return (names[i]);
		i++;
	}
	return (NULL);
}
