#include "cub3d.h"

static void
	ft_map_save(char *line, t_map *map, int i)
{
	char	**tmp;
	int		j;

	j = -1;
	tmp = map->map;
	while (tmp && i && ++j <= i)
		tmp[j] = map->map[j];;
	map->map = ft_calloc(i + 2, sizeof(*map->map));
	if (!map->map)
		ft_fail(ERR_SYS_MALLOC);
	j = -1;
	while (tmp && i && ++j <= i)
		map->map[j] = tmp[j];
	map->map[i] = line;
	if (i)
	{
		if (map->width < (int)ft_strlen(map->map[i]))
			map->width = (int)ft_strlen(map->map[i]);
		free(tmp);
	}
}

static void
	ft_map_resize(t_map *map)
{
	char	**tmp;
	int		i;

	tmp = ft_calloc(map->height + 1, sizeof(*tmp));
	if (!tmp)
		ft_fail(ERR_SYS_MALLOC);

	printf("%d\n", map->width);
	i = -1;
	while (++i < map->height)
	{
		tmp[i] = ft_calloc(sizeof(**tmp), map->width + 1);
		if (tmp[i] == NULL)
			ft_fail(ERR_SYS_MALLOC);
		ft_memset(tmp[i], SPACE, map->width);
		ft_memcpy(tmp[i], map->map[i], ft_strlen(map->map[i]));
	}
}

void
	ft_map_read(int fd, t_map *map)
{
	int		ret;
	char	*line;
	int		i;

	i = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_map_save(line, map, i);
		i++;
	}
	map->height = i;
	ft_map_resize(map);
}
