#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_engine.h"

#define KEYSPEED 0.05
#define MOUSPEED -0.0075
#define TOLERANCE 0.5

static void
	ft_execute_movement(t_map *map, double dir_x, double dir_y)
{
	if (map->map
		[(int)(map->player[Y] + dir_y * KEYSPEED)]
		[(int)(map->player[X])]
		== FLOOR)
		map->player[Y] += dir_y * KEYSPEED;
	if (map->map
		[(int)(map->player[Y])]
		[(int)(map->player[X] + dir_x * KEYSPEED)]
		== FLOOR)
		map->player[X] += dir_x * KEYSPEED;
}

void
	ft_movement(t_map *map, int key)
{
	double	dir_x;
	double	dir_y;

	if (key == KEY_W || key == KEY_S)
	{
		dir_x = map->dir[X];
		dir_y = map->dir[Y];
	}
	else
	{
		dir_x = map->camera[X];
		dir_y = map->camera[Y];
	}
	if (key == KEY_S || key == KEY_A)
	{
		dir_x *= -1.0;
		dir_y *= -1.0;
	}
	ft_execute_movement(map, dir_x, dir_y);
}

void
	ft_rotation(t_map *map, int type, int value)
{
	double	rotation;
	double	old_dir_x;
	double	old_camera_x;

	if (type == KEYBOARD)
	{
		rotation = KEYSPEED;
		if (value == KEY_ARR_L)
			rotation *= -1;
	}
	else
		rotation = value * MOUSPEED;
	old_dir_x = map->dir[X];
	map->dir[X] = map->dir[X] * cos(rotation) - map->dir[Y] * sin(rotation);
	map->dir[Y] = old_dir_x * sin(rotation) + map->dir[Y] * cos(rotation);
	old_camera_x = map->camera[X];
	map->camera[X] = (
			map->camera[X] * cos(rotation) - map->camera[Y] * sin(rotation));
	map->camera[Y] = (
			old_camera_x * sin(rotation) + map->camera[Y] * cos(rotation));
}
