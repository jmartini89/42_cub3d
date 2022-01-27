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
	while (++i < 4)
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
	return i;
}

void
	ft_types(int fd, t_map *map)
{
	int		ret;
	char	*line;
	char	**split;

	int test = 0;

	ft_types_init(map);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		split = ft_split(line, SPACE);
		if (!split)
			ft_fail(ERR_SYS_MALLOC);
		if (!(ft_split_cnt(split) % 2)
			|| (ft_split_cnt(split) == 1 && !ft_strlen(split[0])))
		{
			test++;
			if (split[0]) printf("%s\n", split[0]);
			else printf("CIAO\n");
			if (test == 3) return;
		//		IF (LINE != VALID) FAIL
		//		PARSE
		//		IF (TYPES == END) RETURN
		}
		ft_fail(ERR_GENERIC);
	}
	//	FAIL
}
