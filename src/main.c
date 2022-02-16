/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <jmartini & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:10:46 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:59 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_utils.h"
#include "c3d_engine.h"

static int
	ft_engine(t_core *core)
{
	ft_mouse(core);
	ft_keyboard(core);
	mlx_sync(1, core->frame.img);
	ft_draw(core);
	mlx_put_image_to_window(
		core->mlx, core->win, core->frame.img, 0, 0);
	mlx_sync(3, core->win);
	if (core->input.exit)
		ft_exit(core);
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
	return (EXIT_SUCCESS);
}
