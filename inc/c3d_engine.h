#ifndef C3D_ENGINE_H
# define C3D_ENGINE_H

# include "c3d_core.h"

# define FOV 0.66
# define KEYBOARD 0
# define MOUSE 1

void	ft_engine_init(t_core *core);

int		ft_keyboard_hook(t_core *core);
void	ft_mouse(t_core *core);

void	ft_input_mov_y(t_map *map, int key);
void	ft_input_mov_x(t_map *map, int key);
void	ft_rotation(t_map *map, int type, int value);

void	ft_raycast(t_core *core);

#endif