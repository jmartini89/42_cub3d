#include "cub3d.h"

int
	main(int argc, char **argv)
{
	if (argc != 2)
		ft_fail(ERR_ARGS);
	ft_parser_init(argv[1]);
	return (EXIT_SUCCESS);
}
