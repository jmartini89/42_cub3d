#include "cub3d.h"
#include "cube_core.h"
#include "cube_parser.h"
#include "cube_errors.h"
#include "cube_utils.h"

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
	ft_engine(t_core *core)
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

static int
	ft_input(t_core *core)
{
	mlx_hook(core->win, 2, 1L << 0, ft_keys, core);
	mlx_hook(core->win, 17, 1L << 17, ft_exit_btn, core);
	return (0);
}

static void
	ft_init(t_core *core)
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

	core->exit = 0;
}

int
	main(int argc, char **argv)
{
	t_core	core;

	if (argc != 2)
		ft_fail("Main: Wrong number of arguments");
	ft_parser(&core, argv[1]);

	ft_init(&core);
	ft_input(&core);
	mlx_loop_hook(core.mlx, ft_engine, &core);
	mlx_loop(core.mlx);

	ft_garbage_collector(&core);
	return (EXIT_SUCCESS);
}
