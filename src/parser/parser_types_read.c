#include "c3d_libs.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

static int
	ft_arr_rgb(int *arr)
{
	return (arr[0] << 16 | arr[1] << 8 | arr[2]);
}

static int
	ft_end_check(t_types *types)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!types->textures[i])
			return (FALSE);
	i = -1;
	while (++i < 3)
		if (types->floor[i] == -1 || types->ceiling[i] == -1)
			return (FALSE);
	types->floor_rgb = ft_arr_rgb(types->floor);
	types->ceiling_rgb = ft_arr_rgb(types->ceiling);
	return (TRUE);
}

void
	ft_types_read(int fd, t_types *types)
{
	int		ret;
	char	*line;
	char	**split;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		split = ft_split(line, SPACE);
		if (split == NULL)
			ft_fail(strerror(errno));
		free(line);
		if (ft_split_cnt(split) % 2)
			ft_fail(ERR_PARSE_TYPE_ARGS_LINE);
		ft_types_args(types, split);
		if (ft_end_check(types))
			return ;
	}
	ft_fail(ERR_PARSE_TYPE_ARGS);
}
