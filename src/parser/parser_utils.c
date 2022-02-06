#include "c3d_libs.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

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
