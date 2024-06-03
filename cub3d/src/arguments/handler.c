#include "cub.h"

static void	validate_args_count(int argc)
{
	if (argc != 2)
	{
		printf("Invalid arguments, Usage: ./cub3D <path_to_map>\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

static void	validate_file(char *map_arg, int size)
{
	if (!ft_strnstr(map_arg, ".cub", size))
	{
		printf("The map should be in the '.cub' format\n");
		exit(EXIT_FAILURE);
	}
	if (open(map_arg, O_RDONLY) == -1)
	{
		printf("Invalid map file\n");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	args_handler(int argc, char **argv)
{
	char	*map_arg;
	int		map_arg_len;

	validate_args_count(argc);
	map_arg = argv[1];
	map_arg_len = ft_strlen(map_arg);
	validate_file(map_arg, map_arg_len);
	return ;
}