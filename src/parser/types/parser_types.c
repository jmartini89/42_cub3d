#include <cub3d.h>
#include <cube_errors.h>
#include <cube_parser.h>
#include <cube_utils.h>

static int
	ft_end_check(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!map->types.textures[i])
			return (FALSE);
	i = -1;
	while (++i < 3)
		if (map->types.floor[i] == -1 || map->types.ceiling[i] == -1)
			return (FALSE);
	return (TRUE);
}

void
	ft_types_read(int fd, t_map *map)
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
		ft_types_args(map, split);
		if (ft_end_check(map))
			return ;
	}
	ft_fail(ERR_PARSE_TYPE_ARGS);
}
