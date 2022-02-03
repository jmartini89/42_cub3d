#include "cub3d.h"
#include "cube_parser.h"
#include "cube_errors.h"
#include "cube_utils.h"

int
	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		ft_fail(ERR_ARGS);
	ft_parser(&map, argv[1]);
	ft_garbage_collector(&map);
	exit(EXIT_SUCCESS);
}
