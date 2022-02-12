#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

static void
	ft_mouse_state(t_core *core)
{
	if (core->input.mouse_state == TRUE)
	{
		mlx_mouse_show();
		core->input.mouse_state = FALSE;
		return ;
	}
	mlx_mouse_hide();
	mlx_mouse_get_pos(core->win, &core->input.mouse_x, &core->input.mouse_y);
	if (core->input.mouse_x <= 0 || core->input.mouse_x >= FRAME_W
		|| core->input.mouse_y <= 0 || core->input.mouse_y >= FRAME_H)
	{
		mlx_mouse_move(core->win, FRAME_W / 2, core->frame.h / 2);
		core->input.mouse_x = FRAME_W / 2;
	}
	core->input.mouse_state = TRUE;
}

static int
	ft_key_press(int key, t_core *core)
{
	if (key == KEY_W || key == KEY_S
		|| key == KEY_A || key == KEY_D
		|| key == KEY_ARR_L || key == KEY_ARR_R)
	{
		core->input.key_state = TRUE;
		core->input.key = key;
	}
	else if (key == KEY_SPACE)
		ft_mouse_state(core);
	else if (key == KEY_ESC)
		core->input.exit = 1;
	return (1);
}

static int
	ft_key_release(int key, t_input *input)
{
	(void)key;
	input->key_state = FALSE;
	return (1);
}

static int
	ft_exit_btn(t_input *input)
{
	input->exit = 1;
	return (1);
}

int
	ft_event_hook(t_core *core)
{
	mlx_hook(core->win, 2, 1L << 0, ft_key_press, core);
	mlx_hook(core->win, 3, 1L << 1, ft_key_release, &core->input);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, &core->input);
	return (1);
}
