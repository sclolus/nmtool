
NAME= ft_nm
NAME_2=ft_otool
SRC=srcs/nm/main.c \
	srcs/nm/nm.c \
	srcs/nm/parse_flags.c \
	srcs/nm/ft_put_usage_nm.c \
	srcs/nm/init_nm_process_info.c \
	srcs/nm/nm_find_section.c \
	srcs/nm/nm_get_string_table_entry.c \
	srcs/nm/nm_get_symbols.c \
	srcs/nm/nm_print_symbol.c \
	srcs/nm/ofile/get_ofile_type.c \
	srcs/nm/ofile/get_ofile.c \
	srcs/nm/ofile/map_file.c \
	srcs/nm/ofile/munmap_file.c \
	srcs/nm/ofile/get_macho_host_byte_sex.c \
	srcs/nm/ofile/load_macho_ofile.c \
	srcs/nm/ofile/get_host_byte_sex.c \
	srcs/nm/ofile/set_ofile_mh.c \
	srcs/nm/ofile/set_ofile_load_commands.c \
	srcs/nm/ofile/load_fat_ofile.c \
	srcs/nm/ofile/ofile_swap_fat_hdrs.c \
	srcs/nm/ofile/get_cputype_name.c \
	srcs/nm/ofile/ofile_swap_macho_load_commands.c \
	srcs/nm/ofile/ofile_swap_macho_hdr.c \
	srcs/nm/ofile/macho_swappers/swap_lc_segment.c \
	srcs/nm/ofile/macho_swappers/swap_lc_segment_64.c \
	srcs/nm/ofile/macho_swappers/swap_lc_symtab.c \
	srcs/nm/ofile/macho_swappers/swap_lc_symseg.c \
	srcs/nm/ofile/macho_swappers/swap_section.c \
	srcs/nm/ofile/macho_swappers/swap_section_64.c \
	srcs/nm/ofile/get_nsects.c \
	srcs/nm/ofile/get_nsects_64.c \
	srcs/nm/ofile/ofile_find_lc.c \
	srcs/nm/ofile/ofile_get_symbol_table_lc.c \
	srcs/nm/ofile/ofile_get_dynamic_symbol_table_lc.c \
	srcs/nm/ofile/ofile_get_nsegs.c \
	srcs/nm/ofile/ofile_get_nsegs_64.c \
	srcs/nm/ofile/ofile_get_sections.c \
	srcs/nm/ofile/ofile_get_sections_64.c \
	srcs/nm/ofile/ofile_get_segments.c \
	srcs/nm/ofile/ofile_get_segments_64.c

SRC_2=srcs/otool/main.c \
	srcs/otool/map_otool_file.c \
	srcs/otool/ft_otool.c

HDRS= ./includes/ft_nm.h ./includes/ft_ofile.h #includes/nm.h includes/otool.h
OBJ= $(SRC:.c=.o)
OBJ_2= $(SRC_2:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Weverything -Wall -Werror -Wextra -g3 -Og  -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LIBFT_PATH=./libft
FLAGS= -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes

all: submodule $(NAME)

submodule:
	@echo $(OBJ)
	@make -C libft/

$(NAME): $(OBJ)
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
