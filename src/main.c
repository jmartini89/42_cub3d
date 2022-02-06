#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_utils.h"
#include "c3d_engine.h"

static void
	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < img->w && y >= 0 && y < img->h && color < 0xff000000)
	{
		dst = img->addr + ((y * img->size_line) + (x * img->pixel));
		*(unsigned int *)dst = color;
	}
}

static void
	ft_background(t_img *frame)
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
		*dst = 0x31ccbf;
		dst++;
		i += pixel;
	}
	while (i < below)
	{
		*dst = 0x32a852;
		dst++;
		i += pixel;
	}
}

static void
	ft_raster(t_core *core)
{
	ft_background(&core->frame);
	ft_pixel_put(&core->frame, 200, 200, 0xff1100);
	ft_pixel_put(&core->frame, 300, 300, 0xff1100);
}

#include <time.h>
static int
	ft_gfx(t_core *core)
{
	clock_t	begin = clock();
	// mlx_sync(1, core->frame.img);
	ft_raster(core);
	// mlx_put_image_to_window(
	// 	core->mlx, core->win, core->frame.img, 0, 0);
	// mlx_sync(3, core->win);
	clock_t	end = clock();
	clock_t	delta = end - begin;
	printf("%f\n", delta / 1000.0);
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
	ft_input(&core);
	mlx_loop_hook(core.mlx, ft_gfx, &core);
	mlx_loop(core.mlx);

	ft_garbage_collector(&core);
	return (EXIT_SUCCESS);
}
