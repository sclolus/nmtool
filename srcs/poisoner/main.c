#include "poisoner.h"

int	main(int argc, char **argv)
{
	t_ofile			*ofile;
	t_poison_list	*plist;
	char			*poisoned_filename;
	int				poisoned_file_fd;
	t_gen_config	config;
	uint32_t		i;

	srand((unsigned int)clock());
	i = 1;
	config = (t_gen_config){NULL, 2, {true, true, true, true, true}, true, (uint32_t)rand() % 2 == 0, {0}};
	while (i < (uint32_t)argc)
	{
		if (!(ofile = get_ofile(argv[i])))
			return (EXIT_FAILURE);
		allocate_poisoned_zone(ofile);
		if (ofile->ofile_type == OFILE_UNKNOWN)
		{
			ft_error(3, (char *[]){argv[0], ": ",
						ERR_UNKNOWN_FILE_FORMAT}, 0);
			munmap_file(ofile);
			i++;
			continue ;
		}
		allocate_poisoned_zone(ofile);
		if (!(plist = poison(ofile, &config)))
			exit(EXIT_FAILURE);
		if (NULL == (poisoned_filename = get_poisoned_file_name(argv[i], plist)))
		{
			perror("poisoner: ");
			return (EXIT_FAILURE);
		}
		if (-1 == (poisoned_file_fd = open(poisoned_filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU)))
		{
			perror("poisoner: ");
			return (EXIT_FAILURE);
		}
		if (config.truncate && plist->truncation_addr)
			write(poisoned_file_fd, poisoned_zone_vm_addr, (uint64_t)plist->truncation_addr - (uint64_t)poisoned_zone_vm_addr);
		else
			write(poisoned_file_fd, poisoned_zone_vm_addr, ofile->file_size);
		free_poison_list(plist);
		assert(deallocate_poisoned_zone(ofile) == 0);
		ft_printf("Created file: %s\n", poisoned_filename);
		free(poisoned_filename);
		if (munmap_file(ofile))
		{
			perror(NULL);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}
