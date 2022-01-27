#include "cub3d.h"

static void
	ft_check_spawn(t_map *map, int x, int y)
{
	if (map->map[y][x] == FLOOR)
		return ;
	if (map->player[Y])
		ft_fail(ERR_PARSE_SPAWN);
	map->player[Y] = y;
	map->player[X] = x;
}

static void
	ft_check_valid_walkable(t_map *map, int x, int y)
{
	if ((x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
		|| (map->map[y][x + 1] && map->map[y][x + 1] == VOID)
		|| (map->map[y][x - 1] && map->map[y][x - 1] == VOID)
		|| (map->map[y + 1][x] && map->map[y + 1][x] == VOID)
		|| (map->map[y - 1][x] && map->map[y - 1][x] == VOID)
		|| (map->map[y + 1][x + 1] && map->map[y + 1][x + 1] == VOID)
		|| (map->map[y + 1][x - 1] && map->map[y + 1][x - 1] == VOID)
		|| (map->map[y - 1][x + 1] && map->map[y - 1][x + 1] == VOID)
		|| (map->map[y - 1][x - 1] && map->map[y - 1][x - 1] == VOID))
		ft_fail(ERR_PARSE_MAP);
	return ;
}

static int
	ft_is_walkable(t_map *map, int x, int y)
{
	if (map->map[y][x]
		&& (map->map[y][x] == FLOOR
		|| map->map[y][x] == NORTH
		|| map->map[y][x] == SOUTH
		|| map->map[y][x] == EAST
		|| map->map[y][x] == WEST))
		return (TRUE);
	return (FALSE);
}

void
	ft_map_check(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (ft_is_walkable(map, x, y))
			{
				ft_check_valid_walkable(map, x, y);
				ft_check_spawn(map, x, y);
			}
		}
	}
	if (!map->player[Y])
		ft_fail(ERR_PARSE_SPAWN);
}