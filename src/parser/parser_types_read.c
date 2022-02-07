#include "c3d_libs.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

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
	types->floor_rgb =
		(types->floor[0] << 16 | types->floor[1] << 8 | types->floor[2]);
	types->ceiling_rgb =
		(types->ceiling[0] << 16 | types->ceiling[1] << 8 | types->ceiling[2]);
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
