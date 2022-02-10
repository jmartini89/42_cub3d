#ifndef C3D_CORE_H
# define C3D_CORE_H

# define FALSE 0
# define TRUE 1

# define Y 0
# define X 1

typedef struct s_types
{
	char	*textures[4];
	int		floor[3];
	int		ceiling[3];
	int		floor_rgb;
	int		ceiling_rgb;
}	t_types;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	double	player[2];
	double	dir[2];
	double	camera[2];
}	t_map;

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

typedef struct s_core
{
	void		*mlx;
	void		*win;
	t_img		frame;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_map		map;
	t_types		types;
	t_input		input;
}				t_core;

#endif