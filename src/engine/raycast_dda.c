/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <jmartini & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:14 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:15 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_libs.h"
#include "c3d_engine.h"
#include "c3d_core.h"
#include "c3d_parser.h"

void
	ft_delta_len(t_raycast *rc)
{
	if (rc->ray_dir[X] == 0)
		rc->delta_dist[X] = 1.0;
	else
		rc->delta_dist[X] = fabs(1 / rc->ray_dir[X]);
	if (rc->ray_dir[Y] == 0)
		rc->delta_dist[Y] = 1.0;
	else
		rc->delta_dist[Y] = fabs(1 / rc->ray_dir[Y]);
}

void
	ft_side_len(t_map *map, t_raycast *rc)
{
	if (rc->ray_dir[X] < 0)
	{
		rc->step[X] = -1;
		rc->side_dist[X] = (
				(map->player[X] - rc->map[X]) * rc->delta_dist[X]);
	}
	else if (rc->ray_dir[X] > 0)
	{
		rc->step[X] = 1;
		rc->side_dist[X] = (
				(rc->map[X] + 1.0 - map->player[X]) * rc->delta_dist[X]);
	}
	if (rc->ray_dir[Y] < 0)
	{
		rc->step[Y] = -1;
		rc->side_dist[Y] = (
				(map->player[Y] - rc->map[Y]) * rc->delta_dist[Y]);
	}
	else if (rc->ray_dir[Y] > 0)
	{
		rc->step[Y] = 1;
		rc->side_dist[Y] = (
				(rc->map[Y] + 1.0 - map->player[Y]) * rc->delta_dist[Y]);
	}
}

void
	ft_dda(t_map *map, t_raycast *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist[X] < rc->side_dist[Y])
		{
			rc->side_dist[X] += rc->delta_dist[X];
			rc->map[X] += rc->step[X];
			rc->side = 0;
		}
		else
		{
			rc->side_dist[Y] += rc->delta_dist[Y];
			rc->map[Y] += rc->step[Y];
			rc->side = 1;
		}
		if (map->map[rc->map[Y]][rc->map[X]] == WALL)
			hit = 1;
	}
}
