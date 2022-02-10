#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

static void
	ft_mouse_state(t_core *core)
{
	if (core->mouse_state == FALSE)
	{
		mlx_mouse_hide();
		core->mouse_state = TRUE;
		return ;
	}
	mlx_mouse_show();
	core->mouse_state = FALSE;
}

static int
	ft_keys(int key, t_core *core)
{
	if (key == KEY_W || key == KEY_S
		|| key == KEY_A || key == KEY_D)
		ft_movement(&core->map, key);
	if (key == KEY_ARR_L || key == KEY_ARR_R)
		ft_rotation(&core->map, KEYBOARD, key);
	if (key == KEY_SPACE)
		ft_mouse_state(core);
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
	ft_keyboard_hook(t_core *core)
{
	mlx_hook(core->win, 2, 1L << 0, ft_keys, core);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, core);
	return (0);
}

void
	ft_mouse(t_core *core)
{
	int	mouse;

	if (core->mouse_state == FALSE)
		return ;
	mouse = core->mouse_x;
	mlx_mouse_get_pos(core->win, &core->mouse_x, &core->mouse_y);
	if (mouse != core->mouse_x)
		ft_rotation(&core->map, MOUSE, mouse - core->mouse_x);
	if (core->mouse_x >= core->frame.w || core->mouse_x <= core->frame.w)
	{
		mlx_mouse_move(core->win, core->frame.w / 2, core->frame.h / 2);
		core->mouse_x = core->frame.w / 2;
	}
}
