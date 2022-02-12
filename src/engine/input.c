#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

void
	ft_mouse(t_core *core)
{
	int	mouse;

	if (core->input.mouse_state == FALSE)
		return ;
	mouse = core->input.mouse_x;
	mlx_mouse_get_pos(core->win, &core->input.mouse_x, &core->input.mouse_y);
	if (mouse != core->input.mouse_x)
		ft_rotation(&core->map, MOUSE, mouse - core->input.mouse_x);
	if (core->input.mouse_x <= 0 || core->input.mouse_x >= FRAME_W
		|| core->input.mouse_y <= 0 || core->input.mouse_y >= FRAME_H)
	{
		mlx_mouse_move(core->win, FRAME_W / 2, core->frame.h / 2);
		core->input.mouse_x = FRAME_W / 2;
	}
}

void
	ft_keyboard(t_core *core)
{
	if (core->input.key_state == FALSE)
		return ;
	if (core->input.key == KEY_ARR_L || core->input.key == KEY_ARR_R)
		ft_rotation(&core->map, KEYBOARD, core->input.key);
	else
		ft_movement(&core->map, core->input.key);
}
