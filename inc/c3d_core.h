#ifndef C3D_CORE_H
# define C3D_CORE_H

# define FALSE 0
# define TRUE 1

# define Y 0
# define X 1

# define KEY_W 0xd
# define KEY_A 0x0
# define KEY_S 0x1
# define KEY_D 0x2
# define KEY_ARR_L 0x7b
# define KEY_ARR_R 0x7c
# define KEY_ESC 0x35
# define KEY_SPACE 0x31

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

typedef struct s_core
{
	void		*mlx;
	void		*win;
	int			exit;
	t_img		frame;
	t_img		tex_n;
	t_img		tex_s;
	t_img		tex_e;
	t_img		tex_w;
	t_map		map;
	t_types		types;
}				t_core;

#endif