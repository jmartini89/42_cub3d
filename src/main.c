#include "cub3d.h"

int
	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_fail(ERR_ARGS);
	ft_parser_init(&map, argv[1]);
	return (EXIT_SUCCESS);
}
