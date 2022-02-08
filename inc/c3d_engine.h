#ifndef C3D_ENGINE_H
# define C3D_ENGINE_H

# include "c3d_core.h"

# define FOV 0.66
# define KEYBOARD 0
# define MOUSE 1

typedef struct s_raycast
{
	double	ray_dir[2];
	double	delta_dist[2];
	double	side_dist[2];
	int		map[2];
	int		step[2];
	int		side;
	double	perp_wall_dist;
	int		draw_start;
	int		draw_end;
}			t_raycast;

void	ft_engine_init(t_core *core);

int		ft_keyboard_hook(t_core *core);
void	ft_mouse(t_core *core);

void	ft_input_mov_y(t_map *map, int key);
void	ft_input_mov_x(t_map *map, int key);
void	ft_rotation(t_map *map, int type, int value);

void	ft_draw(t_core *core);
void	ft_verline(
			t_core *core, int x, int drawStart, int drawEnd, int color);
void	ft_raycast(t_core *core);

#endif