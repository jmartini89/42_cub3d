#include "cub3d.h"
#include "cube_parser.h"

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
	int	i;

	i = -1;
	while (++i < 4)
		free(map->types.textures[i]);
	ft_clean_matrix(map->map);
}
