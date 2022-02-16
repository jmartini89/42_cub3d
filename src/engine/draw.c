/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <jmartini & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:29 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:30 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

#define LOGO_OFFSET 25

static void
	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < FRAME_W && y >= 0 && y < FRAME_H && color < 0xff000000)
	{
		dst = img->addr + ((y * img->size_line) + (x * img->pixel));
		*(unsigned int *)dst = color;
	}
}

void
	ft_ver_tex(t_img *frame, t_img *texture, t_raycast *rc, int x)
{
	int		y;
	char	*color;
	double	tex_step;
	double	tex_pos;

	tex_step = 1.0 * texture->w / rc->line_height;
	tex_pos = (
			(rc->draw_start - FRAME_H / 2 + rc->line_height / 2) * tex_step);
	y = rc->draw_start;
	while (y <= rc->draw_end)
	{
		rc->tex[Y] = (int)tex_pos & (texture->w - 1);
		tex_pos += tex_step;
		color = texture->addr
			+ (texture->size_line * rc->tex[X])
			+ (texture->pixel * rc->tex[Y]);
		ft_pixel_put(frame, x, y, *(unsigned int *)color);
		y++;
	}
}

static void
	ft_background(t_img *frame, int ceiling, int floor)
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
		*dst = ceiling;
		dst++;
		i += pixel;
	}
	while (i < below)
	{
		*dst = floor;
		dst++;
		i += pixel;
	}
}

static void
	ft_logo(t_img *frame, t_img *logo)
{
	static int	counter;
	char		*color;
	int			y;
	int			x;

	y = -1;
	while (++y < logo->h / 60)
	{
		x = -1;
		while (++x < logo->w)
		{
			color = logo->addr + (logo->size_line * y) + (logo->pixel * x)
				+ (logo->size_line * counter * (logo->h / 60));
			ft_pixel_put(frame,
				x + FRAME_W - logo->w - LOGO_OFFSET,
				y + LOGO_OFFSET,
				*(unsigned int *)color);
		}
	}
	counter++;
	if (counter == 60)
		counter = 0;
}

void
	ft_draw(t_core *core)
{
	ft_background(
		&core->frame, core->types.ceiling_rgb, core->types.floor_rgb);
	ft_raycast(core);
	ft_logo(&core->frame, &core->logo);
}
