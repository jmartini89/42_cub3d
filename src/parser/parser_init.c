#include "cub3d.h"

static void
	ft_check_extension(char *arg)
{
	int	len;

	len = strlen(arg);
	if (len < 5 || ft_strncmp(&arg[len - 4], ".cub", 4))
		ft_fail(ERR_PARSE_EXT);
}

void
	ft_parser_init(char *arg)
{
	int	fd;

	ft_check_extension(arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
}
