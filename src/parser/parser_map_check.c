#include "c3d_libs.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

static void
	ft_check_spawn(t_map *map, int x, int y)
{
	if (map->map[y][x] == FLOOR)
		return ;
	if (map->player[Y])
		ft_fail(ERR_PARSE_SPAWN);
	map->player[Y] = y + 0.5;
	map->player[X] = x + 0.5;
	if (map->map[y][x] == NORTH)
		map->dir[Y] = -1;
	if (map->map[y][x] == SOUTH)
		map->dir[Y] = 1;
	if (map->map[y][x] == EAST)
		map->dir[X] = 1;
	if (map->map[y][x] == WEST)
		map->dir[X] = -1;
	map->map[y][x] = FLOOR;
}

static void
	ft_check_valid_walkable(t_map *map, int x, int y)
{
	if ((x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
		|| (map->map[y][x + 1] && map->map[y][x + 1] == SPACE)
		|| (map->map[y][x - 1] && map->map[y][x - 1] == SPACE)
		|| (map->map[y + 1][x] && map->map[y + 1][x] == SPACE)
		|| (map->map[y - 1][x] && map->map[y - 1][x] == SPACE)
		|| (map->map[y + 1][x + 1] && map->map[y + 1][x + 1] == SPACE)
		|| (map->map[y + 1][x - 1] && map->map[y + 1][x - 1] == SPACE)
		|| (map->map[y - 1][x + 1] && map->map[y - 1][x + 1] == SPACE)
		|| (map->map[y - 1][x - 1] && map->map[y - 1][x - 1] == SPACE))
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

static void
	ft_valid_char(char c)
{
	if (c != SPACE && c != FLOOR && c != WALL
		&& c != NORTH && c != SOUTH && c != EAST && c != WEST)
		ft_fail(ERR_PARSE_CHAR);
	return ;
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
			ft_valid_char(map->map[y][x]);
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
