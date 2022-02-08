#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_utils.h"
#include "c3d_engine.h"

static void
	ft_background(t_img *frame, int ceiling, int floor)
{
	unsigned int	*dst;
	int				i;
	int				above;
	int				below;
	int				pixel;
	
	dst = (unsigned int *)frame->addr;
	above = (frame->size_line * frame->h) / 2;
	below = frame->size_line * frame->h;
	pixel = frame->pixel;
	i = 0;
	while (i < above)
	{
		*dst = ceiling;
		dst++;
		i += pixel;
	}
	while (i < below)
	{
		*dst = floor;
		dst++;
		i += pixel;
	}
}

static void
	ft_raster(t_core *core)
{
	ft_background(
		&core->frame, core->types.ceiling_rgb, core->types.floor_rgb);
	ft_raycast(core);
}

#include <time.h>
static int
	ft_gfx(t_core *core)
{
	// clock_t	begin = clock();

	ft_mouse(core);

	mlx_sync(1, core->frame.img);
	ft_raster(core);
	mlx_put_image_to_window(
		core->mlx, core->win, core->frame.img, 0, 0);
	mlx_sync(3, core->win);

	// clock_t	end = clock();
	// clock_t	delta = end - begin;
	// printf("%f\n", delta / 1000.0);

	if (core->exit)
	{
		exit(0);
		// ft_exit(core);
	}
	return (0);
}

int
	main(int argc, char **argv)
{
	t_core	core;

	if (argc != 2)
		ft_fail("Main: Wrong number of arguments");
	ft_parser(&core, argv[1]);

	ft_engine_init(&core);
	ft_keyboard_hook(&core);
	mlx_loop_hook(core.mlx, ft_gfx, &core);
	mlx_loop(core.mlx);

	ft_garbage_collector(&core);
	return (EXIT_SUCCESS);
}
