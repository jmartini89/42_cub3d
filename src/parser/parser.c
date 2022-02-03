#include "cub3d.h"
#include "cube_parser.h"
#include "cube_errors.h"

static void
	ft_check_file_extension(char *arg)
{
	int	len;

	len = strlen(arg);
	if (len < 5 || ft_strncmp(&arg[len - 4], ".cub", 4))
		ft_fail(ERR_PARSE_EXT);
}

static void
	ft_init_args(t_map *map)
{
	int	i;

	map->map = NULL;
	map->width = 0;
	map->height = 0;
	map->player[Y] = 0;
	map->player[X] = 0;
	i = -1;
	while (++i < 4)
		map->types.textures[i] = NULL;
	i = -1;
	while (++i < 3)
	{
		map->types.floor[i] = -1;
		map->types.ceiling[i] = -1;
	}
}

void
	ft_parser(t_map *map, char *arg)
{
	int		fd;

	ft_check_file_extension(arg);
	ft_init_args(map);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
	ft_types_read(fd, map);
	ft_map_read(fd, map);
	close(fd);
	ft_map_check(map);

	int i = -1;
	while (++i < 3)
		printf("%d ", map->types.floor[i]);
	printf("\n");
	i = -1;
	while (++i < 3)
		printf("%d ", map->types.ceiling[i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf("%s\n", map->types.textures[i]);
}
