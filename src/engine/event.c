#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

static void
	ft_mouse_state(t_input *input)
{
	if (input->mouse_state == FALSE)
	{
		mlx_mouse_hide();
		input->mouse_state = TRUE;
		return ;
	}
	mlx_mouse_show();
	input->mouse_state = FALSE;
}

static int
	ft_key_press(int key, t_input *input)
{
	if (key == KEY_W || key == KEY_S
		|| key == KEY_A || key == KEY_D
		|| key == KEY_ARR_L || key == KEY_ARR_R)
	{
		input->key_state = TRUE;
		input->key = key;
	}
	if (key == KEY_SPACE)
		ft_mouse_state(input);
	if (key == KEY_ESC)
		input->exit = 1;
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
	mlx_hook(core->win, 2, 1L << 0, ft_key_press, &core->input);
	mlx_hook(core->win, 3, 1L << 1, ft_key_release, &core->input);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, &core->input);
	return (1);
}
