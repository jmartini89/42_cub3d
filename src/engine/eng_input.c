#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"

static void
	ft_input_mov(t_core *core, int key)
{
	if (key == KEY_W)
	{
		if (core->map.map
			[(int)core->map.player[Y] + (int)core->map.dir[Y]]
			[(int)core->map.player[X]]
			== FLOOR)
			core->map.player[Y] += core->map.dir[Y];
		if (core->map.map
			[(int)core->map.player[Y]]
			[(int)core->map.player[X] + (int)core->map.dir[X]]
			== FLOOR)
			core->map.player[X] += core->map.dir[X];
	}
}

static void
	ft_input_rot(t_core *core, int key)
{
	(void)core;
	(void)key;
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
