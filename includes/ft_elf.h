/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sclolus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:25:10 by sclolus           #+#    #+#             */
/*   Updated: 2017/09/20 17:45:51 by sclolus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ELF_H
# define FT_ELF_H

# include <stdbool.h>
# include <stdint.h>

/*
** If encoding == 1, then the ELF file is in 64bits encoding
** else the ELF file is in 32bits encoding
*/

# define ISA_UNDIFINED 0x00
# define ISA_SPARC 0x02
# define ISA_X86 0x03
# define ISA_MIPS 0x08
# define ISA_POWERPC 0x14
# define ISA_S390 0x16
# define ISA_ARM 0x28
# define ISA_SUPERH 0x2A
# define ISA_IA64 0x32
# define ISA_X86_64 0x3E
# define ISA_AARCH64 0xB7
# define ISA_RISC_V 0xF3

typedef struct	s_64_header
{
	uint32_t	magic;
	uint8_t		encoding;
	uint8_t		endian;
	uint8_t		elf_version;
	uint8_t		target_os_abi;
	uint8_t		abi_version;
	uint8_t		elf_pad[7];
	uint16_t	elf_type;
	uint16_t	elf_instruction_set;
	uint32_t	elf_version_2; // dafuq
	uint64_t	entry_point;
	uint64_t	ph_table;
	uint64_t	sh_table;
	uint32_t	elf_flags;
	uint16_t	elf_header_size;
	uint16_t	ph_size;
	uint16_t	sh_size;
	uint16_t	shnum;
	uint16_t	shstrndx;
}				t_64_header;

typedef struct	s_32_header
{
	uint32_t	magic;
	uint8_t		encoding;
	uint8_t		endian;
	uint8_t		elf_version;
	uint8_t		target_os_abi;
	uint8_t		abi_version;
	uint8_t		elf_pad[7];
	uint16_t	elf_type;
	uint16_t	elf_instruction_set;
	uint32_t	elf_version_2; // dafuq
	uint32_t	entry_point;
	uint32_t	ph_table;
	uint32_t	sh_table;
	uint32_t	elf_flags;
	uint16_t	elf_header_size;
	uint16_t	ph_size;
	uint16_t	sh_size;
	uint16_t	shnum;
	uint16_t	shstrndx;
}				t_32_header;

typedef union	u_header_union
{
	t_64_header	header_64;
	t_32_header	header_32;
}				t_header_union;

typedef struct	s_elf_header
{
	t_header_union	header;
	bool			encoding;
}				t_elf_header;

#endif
