#include "cub3d.h"

static void
	ft_types_init(t_map *map)
{
	int	i;

	i = -1;
	map->types.north = NULL;
	map->types.south = NULL;
	map->types.east = NULL;
	map->types.west = NULL;
	while (++i < 3)
	{
		map->types.floor[i] = -1;
		map->types.ceiling[i] = -1;
	}
}

static int
	ft_split_cnt(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

static int
	ft_is_valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
	close(fd);
	return (TRUE);
}

static void
	ft_rgb(char **split, int *type, int j)
{
	int	i;

	i = -1;
	while (++i < 3)
		type[i] = 0;
	free(split[j]);
}

static int
	ft_types_end(t_map *map)
{
	int	i;

	if (!map->types.north || !map->types.south
		|| !map->types.east || !map->types.west)
		return (FALSE);
	i = -1;
	while (++i < 3)
		if (map->types.floor[i] == -1 || map->types.ceiling[i] == -1)
			return (FALSE);
	return (TRUE);
}

static void
	ft_parse_type(char **split, t_map *map, int i)
{
	if (!ft_memcmp(split[i], "NO", strlen(split[i]))
		&& ft_is_valid_path(split[i + 1]) && !map->types.north)
		map->types.north = split[i + 1];
	else if (!ft_memcmp(split[i], "SO", strlen(split[i]))
		&& ft_is_valid_path(split[i + 1]) && !map->types.south)
		map->types.south = split[i + 1];
	else if (!ft_memcmp(split[i], "WE", strlen(split[i]))
		&& ft_is_valid_path(split[i + 1]) && !map->types.west)
		map->types.west = split[i + 1];
	else if (!ft_memcmp(split[i], "EA", strlen(split[i]))
		&& ft_is_valid_path(split[i + 1]) && !map->types.east)
		map->types.east = split[i + 1];
	else if (!ft_memcmp(split[i], "F", strlen(split[i]))
		&& map->types.floor[0] == -1)
		ft_rgb(split, map->types.floor, i + 1);
	else if (!ft_memcmp(split[i], "C", strlen(split[i]))
		&& map->types.ceiling[0] == -1)
		ft_rgb(split, map->types.ceiling, i + 1);
	else
		ft_fail(ERR_PARSE_TYPE);
}

static void
	ft_whatever(t_map *map, char **split)
{
	int	i;

	if (!ft_split_cnt(split))
		return ;
	i = 0;
	while (split[i])
	{
		ft_parse_type(split, map, i);
		free(split[i]);
		if (split[i + 1] && split[i + 2])
			i = +2;
		else
			break ;
	}
	free(split);
}

void
	ft_types(int fd, t_map *map)
{
	int		ret;
	char	*line;
	char	**split;

	ft_types_init(map);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		split = ft_split(line, SPACE);
		if (!split)
			ft_fail(strerror(errno));
		free(line);
		if (ft_split_cnt(split) % 2)
			ft_fail(ERR_PARSE_TYPE_ARGS_LINE);
		ft_whatever(map, split);
		if (ft_types_end(map))
			return ;
	}
	ft_fail(ERR_PARSE_TYPE_ARGS); // DOES THIS EVEN OCCUR?!
}
