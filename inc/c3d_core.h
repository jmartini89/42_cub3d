#ifndef C3D_CORE_H
# define C3D_CORE_H

# define FALSE 0
# define TRUE 1

# define Y 0
# define X 1

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	double	player[2];
	double	dir[2];
	double	camera[2];
}	t_map;

typedef struct s_types
{
	char	*textures[4];
	int		floor[3];
	int		ceiling[3];
	int		floor_rgb;
	int		ceiling_rgb;
}	t_types;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		pixel;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_input
{
	int		key_state;
	int		key;
	int		mouse_state;
	int		mouse_x;
	int		mouse_y;
	int		exit;
}			t_input;

typedef struct s_raycast
{
	double	ray_dir[2];
	double	delta_dist[2];
	double	side_dist[2];
	int		map[2];
	int		step[2];
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex[2];
}			t_raycast;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_types		types;
	t_img		frame;
	t_img		logo;
	t_img		tex[4];
	t_input		input;
	t_raycast	raycast;
}				t_core;

#endif