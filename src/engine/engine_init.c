#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

void
	ft_engine_init(t_core *core)
{
	core->mlx = mlx_init();
	// ft_init_textures(core);

	core->frame.w = 800;
	core->frame.h = 600;
	core->frame.img = mlx_new_image(core->mlx, core->frame.w, core->frame.h);
	core->frame.addr = mlx_get_data_addr(
			core->frame.img, &core->frame.bpp,
			&core->frame.size_line, &core->frame.endian);
	core->frame.pixel = core->frame.bpp / 8;

	core->win = mlx_new_window(
			core->mlx, core->frame.w, core->frame.h, "test");

	core->input.exit = FALSE;
	core->input.key_state = FALSE;
	core->input.mouse_state = FALSE;
	core->input.mouse_x = FALSE;
	core->input.mouse_y = FALSE;
	core->map.camera[X] = -core->map.dir[Y] * FOV;
	core->map.camera[Y] = core->map.dir[X] * FOV;
}
