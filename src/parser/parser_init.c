#include "cub3d.h"

static void
	ft_check_file_extension(char *arg)
{
	int	len;

	len = strlen(arg);
	if (len < 5 || ft_strncmp(&arg[len - 4], ".cub", 4))
		ft_fail(ERR_PARSE_EXT);
}

static void
	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player[Y] = 0;
	map->player[X] = 0;
}


void
	ft_parser_init(t_map *map, char *arg)
{
	int		fd;

	ft_init_map(map);
	ft_check_file_extension(arg);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
	ft_map_read(fd, map);
	close(fd);
	ft_map_check(map);

	for (int j = 0; j < map->height; j++) {
		printf("%s\n", map->map[j]);
		free(map->map[j]);
	}
	free(map->map);
}
