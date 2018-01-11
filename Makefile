NAME= ft_nm
NAME_2=ft_otool
SRC= srcs/nm/main.c \
	srcs/nm/ft_put_nm_usage.c \
	srcs/nm/map_nm_file.c \
	srcs/nm/nm.c \
	srcs/nm/print_segment_info.c \
	srcs/nm/print_section_info.c \
	srcs/nm/parse_ofile.c \
	srcs/nm/parse_ofile_64.c \
	srcs/nm/parse_flags.c \
	srcs/nm/get_special_section_nsects.c \
	srcs/nm/parse_fat_file.c \
	srcs/nm/select_symbol.c \
	srcs/nm/select_symbols.c \
	srcs/nm/set_symbols_names.c \
	srcs/nm/print_symbols.c \
	srcs/nm/sort_symbols.c \
	srcs/nm/parse_ofile_32.c \
	srcs/nm/parse_fat_file_32.c \
	srcs/nm/parse_fat_file_64.c \
	srcs/nm/endian_swap/swap_dyld_info_command.c \
	srcs/nm/endian_swap/swap_dylib.c \
	srcs/nm/endian_swap/swap_dylinker_command.c \
	srcs/nm/endian_swap/swap_dysymtab_command.c \
	srcs/nm/endian_swap/swap_encryption_info_command.c \
	srcs/nm/endian_swap/swap_entry_point_command.c \
	srcs/nm/endian_swap/swap_fvmfile_command.c \
	srcs/nm/endian_swap/swap_fvmlib_command.c \
	srcs/nm/endian_swap/swap_linkedit_data_command.c \
	srcs/nm/endian_swap/swap_linker_option_command.c \
	srcs/nm/endian_swap/swap_mach_header.c \
	srcs/nm/endian_swap/swap_nlist.c \
	srcs/nm/endian_swap/swap_ofile_endiannes.c \
	srcs/nm/endian_swap/swap_prebind_cksum_command.c \
	srcs/nm/endian_swap/swap_prebound_dylib_command.c \
	srcs/nm/endian_swap/swap_routines_command.c \
	srcs/nm/endian_swap/swap_rpath_command.c \
	srcs/nm/endian_swap/swap_segment_command.c \
	srcs/nm/endian_swap/swap_source_version_command.c \
	srcs/nm/endian_swap/swap_sub_client_command.c \
	srcs/nm/endian_swap/swap_sub_framework_command.c \
	srcs/nm/endian_swap/swap_sub_library_command.c \
	srcs/nm/endian_swap/swap_sub_umbrella_command.c \
	srcs/nm/endian_swap/swap_symtab.c \
	srcs/nm/endian_swap/swap_symtab_command.c \
	srcs/nm/endian_swap/swap_thread_command.c \
	srcs/nm/endian_swap/swap_uuid_command.c \
	srcs/nm/endian_swap/swap_version_min_command.c \
	srcs/nm/endian_swap/swap_load_command.c \
	srcs/nm/endian_swap/swap_fat_header.c \
	srcs/nm/endian_swap/swap_fat_archs.c \
	srcs/nm/endian_swap/swap_fat.c

SRC_2=srcs/otool/main.c \
	srcs/otool/map_otool_file.c \
	srcs/otool/ft_otool.c

HDRS= includes/nm.h includes/otool.h
OBJ= $(SRC:.c=.o)
OBJ_2= $(SRC_2:.c=.o)
HDR_PATH= ./libft/includes/
CC= gcc
CC_FLAGS= -v -Ofast -Weverything -Wall -Werror -Wextra -g3  -fsanitize=address -fsanitize-blacklist=my_ignores.txt
LIBFT_PATH=./libft
FLAGS= -L$(LIBFT_PATH) -lft -I$(HDR_PATH) -I./includes

all: submodule $(NAME) $(NAME_2)

submodule:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME)
$(NAME_2): $(OBJ_2)
	$(CC) $(CC_FLAGS) $^ $(FLAGS) -o $(NAME_2)
%.o : %.c $(HDRS)
	$(CC) $(CC_FLAGS) $< -c -I$(HDR_PATH) -I./includes -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all
