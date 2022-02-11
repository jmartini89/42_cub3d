#include "c3d_libs.h"
#include "c3d_core.h"

static void
	ft_clean_matrix(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		free(str[i]);
	free(str);
}

static void
	ft_mlx_close(t_core *core)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(core->mlx, core->tex[i].img);
	if (core->input.mouse_state)
		mlx_mouse_show();
	mlx_destroy_window(core->mlx, core->win);
}

void
	ft_exit(t_core *core)
{
	ft_mlx_close(core);
	ft_clean_matrix(core->map.map);
	exit(EXIT_SUCCESS);
}

void
	ft_fail(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}
