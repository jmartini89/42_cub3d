#include "cub3d.h"

static void
	ft_clean_matrix(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}

void
	ft_garbage_collector(t_map *map)
{
	ft_clean_matrix(map->map);
	free(map->types.north);
	free(map->types.south);
	free(map->types.east);
	free(map->types.west);
}
