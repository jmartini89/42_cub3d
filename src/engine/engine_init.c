#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"
#include "c3d_utils.h"

static void
	ft_textures(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		core->tex[i].img = mlx_xpm_file_to_image(
			core->mlx, core->types.textures[i], &core->tex[i].w, &core->tex[i].h);
		if (core->tex[i].img == NULL)
			ft_fail(ERR_MLX_XPM);
		core->tex[i].addr = mlx_get_data_addr(
			core->tex[i].img, &core->tex[i].bpp, &core->tex[i].size_line, &core->tex[i].endian);
		core->tex[i].pixel = core->tex[i].bpp / 8;
		free(core->types.textures[i]);
		core->types.textures[i] = NULL;
	}
}

static void
	ft_win_frame(t_core *core)
{
	core->frame.w = FRAME_W;
	core->frame.h = FRAME_H;
	core->frame.img = mlx_new_image(core->mlx, FRAME_W, FRAME_H);
	if (core->frame.img == NULL)
			ft_fail(ERR_MLX_IMG);
	core->frame.addr = mlx_get_data_addr(
			core->frame.img, &core->frame.bpp,
			&core->frame.size_line, &core->frame.endian);
	core->frame.pixel = core->frame.bpp / 8;
	core->win = mlx_new_window(
			core->mlx, FRAME_W, FRAME_H, "Cub3D");
	if (core->win == NULL)
		ft_fail(ERR_MLX_WIN);
}

void
	ft_engine_init(t_core *core)
{
	core->input.exit = FALSE;
	core->input.key_state = FALSE;
	core->input.mouse_state = FALSE;
	core->input.mouse_x = FALSE;
	core->input.mouse_y = FALSE;
	core->map.camera[X] = -core->map.dir[Y] * FOV;
	core->map.camera[Y] = core->map.dir[X] * FOV;
	core->mlx = mlx_init();
	if (core->mlx == NULL)
		ft_fail(ERR_MLX_INIT);
	ft_textures(core);
	ft_win_frame(core);
}
