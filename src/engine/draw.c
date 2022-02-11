#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

void
	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < FRAME_W && y >= 0 && y < FRAME_H && color < 0xff000000)
	{
		dst = img->addr + ((y * img->size_line) + (x * img->pixel));
		*(unsigned int *)dst = color;
	}
}

#include <unistd.h>
void
	ft_vertex(t_core *core, int x, t_raycast *rc, t_img *texture)
{
	int		y;
	char	*color;
	double	tex_step;
	double	tex_pos;

	tex_step = 1.0 * TEX_H / rc->line_height;
	tex_pos = (
		(rc->draw_start - FRAME_H / 2 + rc->line_height / 2) * tex_step);
	y = rc->draw_start;
	while (y <= rc->draw_end)
	{
		rc->tex[Y] = (int)tex_pos & (TEX_H - 1);
		tex_pos += tex_step;
		color = texture->addr + (texture->size_line * rc->tex[X]) + (rc->tex[Y] * texture->pixel);
		ft_pixel_put(&core->frame, x, y, *(unsigned int *)color);
		y++;
	}
}

void
	ft_verline(t_core *core, int x, int drawStart, int drawEnd, int color)
{
	int y = 0;
	while (y < FRAME_W)
	{
		if (y >= drawStart && y <= drawEnd)
			ft_pixel_put(&core->frame, x, y, color);
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

void
	ft_draw(t_core *core)
{
	ft_background(
		&core->frame, core->types.ceiling_rgb, core->types.floor_rgb);
	ft_raycast(core);
}
