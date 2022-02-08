#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"

#define MOVSPEED 0.1
#define ROTSPEED 0.05

static void
	ft_input_mov(t_core *core, int key)
{
	double	dirX;
	double	dirY;

	dirX = core->map.dir[X];
	dirY = core->map.dir[Y];
	if (key == KEY_S)
	{
		dirX *= -1.0;
		dirY *= -1.0;
	}
	if (core->map.map
		[(int)(core->map.player[Y] + dirY)]
		[(int)core->map.player[X]]
		== FLOOR)
		core->map.player[Y] += dirY * MOVSPEED;
	if (core->map.map
		[(int)core->map.player[Y]]
		[(int)(core->map.player[X] + dirX)]
		== FLOOR)
		core->map.player[X] += dirX * MOVSPEED;
}

static void
	ft_input_rot(t_core *core, int key)
{
	double	rotation;
	double	oldDirX;
	double	oldCameraX;

	rotation = ROTSPEED;
	if (key == KEY_D)
		rotation *= -1;
	oldDirX = core->map.dir[X];
	core->map.dir[X] = core->map.dir[X] * cos(rotation) - core->map.dir[Y] * sin(rotation);
	core->map.dir[Y] = oldDirX * sin(rotation) + core->map.dir[Y] * cos(rotation);
	oldCameraX = core->map.camera[X];
	core->map.camera[X] = core->map.camera[X] * cos(rotation) - core->map.camera[Y] * sin(rotation);
	core->map.camera[Y] = oldCameraX * sin(rotation) + core->map.camera[Y] * cos(rotation);
}

static int
	ft_keys(int key, t_core *core)
{
	if (key == KEY_W || key == KEY_S)
		ft_input_mov(core, key);
	if (key == KEY_A || key == KEY_D)
		ft_input_rot(core, key);
	if (key == KEY_ESC)
		core->exit = 1;
	return (1);
}

static int
	ft_exit_btn(t_core *core)
{
	core->exit = 1;
	return (1);
}

int
	ft_input(t_core *core)
{
	mlx_hook(core->win, 2, 1L << 0, ft_keys, core);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, core);
	return (0);
}
