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
	ft_is_valid_path(char *split)
{
	int i;

	i = open(split, O_RDONLY);
	if (i == -1)
		ft_fail(ERR_ARGS);
	close(i);
	return;
	
}

void
	ft_is_valid_rgb(char * split)
{
	(void)split;
}


void
	ft_types(int fd, t_map *map)
{
	int		ret;
	char	*line;
	char	**split;
	int		test;

	test = 0;
	ft_types_init(map);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		split = ft_split(line, SPACE);
		if (!split)
			ft_fail(ERR_SYS_MALLOC);
		if (!(ft_split_cnt(split) % 2)
			|| (!ft_strlen(split[0])))
		{
			if(ft_split_cnt(split))
			{
				test++;
				if (!ft_memcmp(split[0], "NO", strlen(split[0]))
					|| !ft_memcmp(split[0], "SO", strlen(split[0]))
					|| !ft_memcmp(split[0], "WE", strlen(split[0]))
					|| !ft_memcmp(split[0], "EA", strlen(split[0])))
					ft_is_valid_path(split[1]);
				else if (!ft_memcmp(split[0], "F", strlen(split[0]))
					|| !ft_memcmp(split[0], "C", strlen(split[0])))
					ft_is_valid_rgb(split[1]);
				else
					ft_fail(ERR_ARGS);
			//		PARSE
			//		IF (TYPES == END) RETURN
			if (test == 4)
				return;

			}
		}
	}
		ft_fail(ERR_GENERIC);
	//	FAIL
}
