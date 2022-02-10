#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_engine.h"

static void
	ft_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	if (x >= 0 && x < img->w && y >= 0 && y < img->h && color < 0xff000000)
	{
		dst = img->addr + ((y * img->size_line) + (x * img->pixel));
		*(unsigned int *)dst = color;
	}
}

void
	ft_verline(t_core *core, int x, int drawStart, int drawEnd, int color)
{
	int y = 0;
	while (y < core->frame.h)
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
