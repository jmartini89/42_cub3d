#include "c3d_libs.h"
#include "c3d_engine.h"
#include "c3d_core.h"
#include "c3d_parser.h"

static void
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

static void
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

static void
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

static void
	ft_distances(t_raycast *rc)
{
	if (rc->side == 0)
		rc->perp_wall_dist = (rc->side_dist[X] - rc->delta_dist[X]);
	else
		rc->perp_wall_dist = (rc->side_dist[Y] - rc->delta_dist[Y]);
	if ((int)rc->perp_wall_dist == 0)
		rc->perp_wall_dist = 1;
	rc->line_height = (int)(FRAME_H / rc->perp_wall_dist);
	rc->draw_start = -rc->line_height / 2 + FRAME_H / 2;
	if (rc->draw_start < 0)
		rc->draw_start = 0;
	rc->draw_end = rc->line_height / 2 + FRAME_H / 2;
	if (rc->draw_end >= FRAME_H)
		rc->draw_end = FRAME_H - 1;
}

t_img *
	ft_wall_tex_picker(t_raycast *rc, t_core *core)
{
	if (rc->map[Y] < core->map.player[Y] && rc->side)
		return (&core->tex[N_TEX]);
	if (rc->map[Y] > core->map.player[Y] && rc->side)
		return (&core->tex[S_TEX]);
	if (rc->map[X] > core->map.player[X] && !rc->side)
		return (&core->tex[E_TEX]);
	if (rc->map[X] < core->map.player[X] && !rc->side)
		return (&core->tex[W_TEX]);
	return (NULL);
}

static void
	ft_tex_calc(t_raycast *rc, t_map *map)
{
	if (rc->side == 0)
		rc->wall_x = map->player[Y] + rc->perp_wall_dist * rc->ray_dir[Y];
	else
		rc->wall_x = map->player[X] + rc->perp_wall_dist * rc->ray_dir[X];
	rc->wall_x -= floor(rc->wall_x);
	rc->tex[X] = (int)rc->wall_x * (double)TEX_W;
	if ((rc->side == 0 && rc->ray_dir[X] > 0)
		|| (rc->side == 1 && rc->ray_dir[Y] < 0))
		rc->tex[X] = TEX_W - rc->tex[X] - 1;
	rc->tex_step = 1.0 * TEX_H / rc->line_height;
	rc->tex_pos = (
		(rc->draw_start - FRAME_H / 2 + rc->line_height / 2) * rc->tex_step);
}

void
	ft_raycast(t_core *core)
{
	t_raycast	rc;
	int			index;
	double		frame_x;
	t_img		*texture;

	index = -1;
	while (++index < FRAME_W)
	{
		frame_x = 2 * index / (double)FRAME_W - 1;
		rc.ray_dir[X] = core->map.dir[X] + core->map.camera[X] * frame_x;
		rc.ray_dir[Y] = core->map.dir[Y] + core->map.camera[Y] * frame_x;
		ft_delta_len(&rc);
		rc.map[X] = (int)core->map.player[X];
		rc.map[Y] = (int)core->map.player[Y];
		ft_side_len(&core->map, &rc);
		ft_dda(&core->map, &rc);
		ft_distances(&rc);
		texture = ft_wall_tex_picker(&rc, core);
		ft_tex_calc(&rc, &core->map);
		ft_vertex(core, index, &rc, texture);
	}
}
