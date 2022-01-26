#include "cub3d.h"

static void
	ft_map_save(char *line, char ***map, int i)
{
	char	**tmp;
	int		j;

	j = -1;
	tmp = *map;
	while (tmp && i && ++j <= i)
		tmp[j] = map[0][j];
	*map = ft_calloc(i + 2, sizeof(**map));
	if (!*map)
		ft_fail("WIP");
	j = -1;
	while (tmp && i && ++j <= i)
		map[0][j] = tmp[j];
	map[0][i] = line;
	if (i)
		free(tmp);
}

void
	ft_map_read(int fd, char ***map)
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
}
