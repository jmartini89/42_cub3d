#include "cub3d.h"
#include "cube_parser.h"
#include "cube_errors.h"

int
	ft_split_cnt(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void
	ft_is_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
	close(fd);
}
