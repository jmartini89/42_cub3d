#ifndef C3D_ENGINE_H
# define C3D_ENGINE_H

# include "c3d_core.h"

# define FOV 0.66

void	ft_engine_init(t_core *core);
int		ft_input(t_core *core);
void	ft_raycast(t_core *core);

#endif