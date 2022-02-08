#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"

#define MOVSPEED 0.1
#define ROTSPEED 0.05

void
	ft_input_mov_y(t_map *map, int key)
{
	double	dir_x;
	double	dir_y;

	dir_x = map->dir[X];
	dir_y = map->dir[Y];
	if (key == KEY_S)
	{
		dir_x *= -1.0;
		dir_y *= -1.0;
	}
	if (map->map
		[(int)(map->player[Y] + dir_y)]
		[(int)(map->player[X])]
		== FLOOR)
		map->player[Y] += dir_y * MOVSPEED;
	if (map->map
		[(int)(map->player[Y])]
		[(int)(map->player[X] + dir_x)]
		== FLOOR)
		map->player[X] += dir_x * MOVSPEED;
}

void
	ft_input_mov_x(t_map *map, int key)
{
	double	dir_x;
	double	dir_y;

	dir_x = map->dir[X];
	dir_y = map->dir[Y];
	if (key == KEY_S)
	{
		dir_x *= -1.0;
		dir_y *= -1.0;
	}
	if (map->map
		[(int)(map->player[Y] + dir_y)]
		[(int)(map->player[X])]
		== FLOOR)
		map->player[Y] += dir_y * MOVSPEED;
	if (map->map
		[(int)(map->player[Y])]
		[(int)(map->player[X] + dir_x)]
		== FLOOR)
		map->player[X] += dir_x * MOVSPEED;
}

void
	ft_input_rot(t_map *map, int key)
{
	double	rotation;
	double	old_dir_x;
	double	old_camera_x;

	rotation = ROTSPEED;
	if (key == KEY_ARR_L)
		rotation *= -1;
	old_dir_x = map->dir[X];
	map->dir[X] = map->dir[X] * cos(rotation) - map->dir[Y] * sin(rotation);
	map->dir[Y] = old_dir_x * sin(rotation) + map->dir[Y] * cos(rotation);
	old_camera_x = map->camera[X];
	map->camera[X] = (
			map->camera[X] * cos(rotation) - map->camera[Y] * sin(rotation));
	map->camera[Y] = (
			old_camera_x * sin(rotation) + map->camera[Y] * cos(rotation));
}
