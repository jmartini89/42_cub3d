#include "c3d_libs.h"
#include "c3d_core.h"

static int	ft_keys(int key, t_core *core)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
	{
		printf("%x\n", key);
		// ft_input_mov(core, key);
	}
	// if (key == KEY_SPACE)
	// 	ft_mouse(core);
	if (key == KEY_ESC)
		core->exit = 1;
	return (1);
}

static int	ft_exit_btn(t_core *core)
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
