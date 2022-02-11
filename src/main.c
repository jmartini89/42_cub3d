#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_utils.h"
#include "c3d_engine.h"

#include <time.h> // TMP
static int
	ft_engine(t_core *core)
{
	// clock_t	begin = clock();

	ft_mouse(core);
	ft_keyboard(core);
	mlx_sync(1, core->frame.img);
	ft_draw(core);
	mlx_put_image_to_window(
		core->mlx, core->win, core->frame.img, 0, 0);
	mlx_sync(3, core->win);

	// clock_t	end = clock();
	// clock_t	delta = end - begin;
	// printf("%f\n", delta / 1000.0);

	if (core->input.exit)
	{
		exit(0);
		// ft_exit(core);
	}
	return (1);
}

int
	main(int argc, char **argv)
{
	t_core	core;

	if (argc != 2)
		ft_fail("Main: Wrong number of arguments");
	ft_parser(&core, argv[1]);
	ft_engine_init(&core);
	ft_event_hook(&core);
	mlx_loop_hook(core.mlx, ft_engine, &core);
	mlx_loop(core.mlx);
	ft_garbage_collector(&core);
	return (EXIT_SUCCESS);
}
