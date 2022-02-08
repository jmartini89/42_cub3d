#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

static int
	ft_keys(int key, t_core *core)
{
	if (key == KEY_W || key == KEY_S)
		ft_input_mov_y(&core->map, key);
	if (key == KEY_A || key == KEY_D)
		ft_input_mov_x(&core->map, key);
	if (key == KEY_ARR_L || key == KEY_ARR_R)
		ft_input_rot(&core->map, key);
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
