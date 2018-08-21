NAME= ft_nm
NAME_2=ft_otool
SRC=srcs/nm/main.c \
	srcs/nm/nm.c \
	srcs/nm/parse_flags.c \
	srcs/nm/ft_put_usage_nm.c \
	srcs/nm/nm_sort_symbols.c \
	srcs/nm/init_nm_process_info.c \
	srcs/nm/nm_find_section.c \
	srcs/nm/nm_get_string_table_entry.c \
	srcs/nm/nm_get_symbols.c \
	srcs/nm/nm_print_symbol.c
SRC_OFILE_LIB=srcs/ofile/get_ofile_type.c \
	srcs/ofile/get_ofile.c \
	srcs/ofile/map_file.c \
	srcs/ofile/munmap_file.c \
	srcs/ofile/get_macho_host_byte_sex.c \
	srcs/ofile/load_macho_ofile.c \
	srcs/ofile/ofile_object_check_addr.c \
	srcs/ofile/get_host_byte_sex.c \
	srcs/ofile/set_ofile_mh.c \
	srcs/ofile/set_ofile_load_commands.c \
	srcs/ofile/load_fat_ofile.c \
	srcs/ofile/ofile_file_check_addr.c \
	srcs/ofile/load_archive_file.c \
	srcs/ofile/ofile_archive_get_member_starting_addr.c \
	srcs/ofile/archive_parse_member_header.c \
	srcs/ofile/ofile_load_narchive_member.c \
	srcs/ofile/ofile_load_narch.c \
	srcs/ofile/ofile_fat_find_arch.c \
	srcs/ofile/ofile_find_n_fat_arch.c \
	srcs/ofile/ofile_find_n_fat_arch_64.c \
	srcs/ofile/ofile_swap_fat_hdrs.c \
	srcs/ofile/get_cputype_name.c \
	srcs/ofile/ofile_swap_macho_load_commands.c \
	srcs/ofile/ofile_swap_macho_hdr.c \
	srcs/ofile/macho_swappers/swap_lc_segment.c \
	srcs/ofile/macho_swappers/swap_lc_segment_64.c \
	srcs/ofile/macho_swappers/swap_lc_symtab.c \
	srcs/ofile/macho_swappers/swap_lc_symseg.c \
	srcs/ofile/macho_swappers/swap_section.c \
	srcs/ofile/macho_swappers/swap_section_64.c \
	srcs/ofile/get_nsects.c \
	srcs/ofile/get_nsects_64.c \
	srcs/ofile/ofile_find_lc.c \
	srcs/ofile/ofile_find_n_lc.c \
	srcs/ofile/ofile_get_n_lc.c \
	srcs/ofile/ofile_object_count_lc.c \
	srcs/ofile/ofile_get_symbol_table_lc.c \
	srcs/ofile/ofile_get_dynamic_symbol_table_lc.c \
	srcs/ofile/ofile_find_n_nlist.c \
	srcs/ofile/ofile_find_n_nlist_64.c \
	srcs/ofile/ofile_find_n_sect.c \
	srcs/ofile/ofile_find_n_sect_64.c \
	srcs/ofile/ofile_get_nsegs.c \
	srcs/ofile/ofile_get_nsegs_64.c \
	srcs/ofile/ofile_get_sections.c \
	srcs/ofile/ofile_get_sections_64.c \
	srcs/ofile/ofile_get_segments.c \
	srcs/ofile/ofile_get_segments_64.c \
	srcs/ofile/ofile_check_object_integrity.c \
	srcs/ofile/integrity_checkers/check_lc_segment_integrity.c \
	srcs/ofile/integrity_checkers/check_lc_symtab_integrity.c \
	srcs/ofile/integrity_checkers/check_lc_segment_64_integrity.c \
	srcs/ofile/integrity_checkers/ofile_check_mach_header_integrity.c
SRC_2=srcs/otool/main.c \
	srcs/otool/map_otool_file.c \
	srcs/otool/ft_otool.c
SRC_POISONER=srcs/poisoner/main.c \
			srcs/poisoner/poisoner.c \
			srcs/poisoner/poison_lc_segment.c \
			srcs/poisoner/poison_lc_symtab.c \
			srcs/poisoner/generate_poison_list.c \
			srcs/poisoner/generate_poison_command.c \
			srcs/poisoner/exec_lc_poisoner.c \
			srcs/poisoner/exec_sub_level_lc_poisoner.c \
			srcs/poisoner/exec_fat_level_poisoner.c \
			srcs/poisoner/exec_macho_level_poisoner.c \
			srcs/poisoner/finder.c \
			srcs/poisoner/allocate_poisoned_zone.c \
			srcs/poisoner/deallocate_poisoned_zone.c \
			srcs/poisoner/map_addr_to_poisoned_zone.c \
			srcs/poisoner/get_poisoned_file_name.c

HDRS= ./includes/ft_nm.h ./includes/ft_ofile.h ./includes/poisoner.h #includes/nm.h includes/otool.h
OBJ= $(SRC:.c=.o)
OBJ_2= $(SRC_2:.c=.o)
OBJ_POISONER= $(SRC_POISONER:.c=.o)
OBJ_OFILE_LIB= $(SRC_OFILE_LIB:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Weverything -Wall -Werror -Wextra -g3 -Og   -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LIBFT_PATH=./libft
FLAGS= -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes

all: submodule $(NAME) poisoner

submodule:
	@echo $(SRC_OFILE_LIB)
	@make -C libft/

$(NAME): $(OBJ) $(OBJ_OFILE_LIB)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
# $(NAME_2): $(OBJ_2)
# 	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME_2)
%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) -I./includes $< -c -I$(HDR_PATH) -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

poisoner: $(OBJ_POISONER) $(OBJ_OFILE_LIB)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o poisoner
