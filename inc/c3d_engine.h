/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <jmartini & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:40 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:41 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_ENGINE_H
# define C3D_ENGINE_H

# include "c3d_core.h"

# define KEY_W 0xd
# define KEY_A 0x0
# define KEY_S 0x1
# define KEY_D 0x2
# define KEY_ARR_L 0x7b
# define KEY_ARR_R 0x7c
# define KEY_ESC 0x35
# define KEY_SPACE 0x31

# define FOV 0.66
# define KEYBOARD 0
# define MOUSE 1

# define FRAME_W 800
# define FRAME_H 600

void	ft_engine_init(t_core *core);

int		ft_event_hook(t_core *core);
void	ft_keyboard(t_core *core);
void	ft_mouse(t_core *core);

void	ft_movement(t_map *map, int key);
void	ft_rotation(t_map *map, int type, int value);

void	ft_draw(t_core *core);
void	ft_ver_tex(
			t_img *frame, t_img *texture, t_raycast *rc, int x);

void	ft_raycast(t_core *core);
void	ft_delta_len(t_raycast *rc);
void	ft_side_len(t_map *map, t_raycast *rc);
void	ft_dda(t_map *map, t_raycast *rc);

#endif