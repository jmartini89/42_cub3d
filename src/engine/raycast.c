#include "c3d_libs.h"
#include "c3d_engine.h"
#include "c3d_core.h"
#include "c3d_parser.h"

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

static void
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

void
	ft_raycast(t_core *core)
{
	double pos_x = core->map.player[X];
	double pos_y = core->map.player[Y];
	double dir_x = core->map.dir[X];
	double dir_y = core->map.dir[Y];
	core->map.camera[X] = -dir_y * FOV;
	core->map.camera[Y] = dir_x * FOV;

	int index = -1;
	while (++index < core->frame.w)
	{
		double frame_x = 2 * index / (double)core->frame.w - 1;
		double ray_dir_x = dir_x + core->map.camera[X] * frame_x;
		double ray_dir_y = dir_y + core->map.camera[Y] * frame_x;

		int mapX = (int)pos_x;
		int mapY = (int)pos_y;

		double sideDistX;
		double sideDistY;

		double deltaDistX;
		double deltaDistY;
		if (ray_dir_x == 0)
			deltaDistX = 1.0;
		else
			deltaDistX = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			deltaDistY = 1.0;
		else
			deltaDistY = fabs(1 / ray_dir_y);

		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if (ray_dir_x < 0)
		{
			stepX = -1;
			sideDistX = (pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - pos_x) * deltaDistX;
		}
		if (ray_dir_y < 0)
		{
			stepY = -1;
			sideDistY = (pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (core->map.map[mapY][mapX] == WALL)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		int lineHeight = (int)(core->frame.h / perpWallDist);


		int drawStart = -lineHeight / 2 + core->frame.h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + core->frame.h / 2;
		if (drawEnd >= core->frame.h)
			drawEnd = core->frame.h - 1;

		int color = 0xff0000;
		if (side == 1)
			color = color / 2;

		ft_verline(core, index, drawStart, drawEnd, color);
	}
}
