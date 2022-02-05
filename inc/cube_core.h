#ifndef CUBE_CORE_H
# define CUBE_CORE_H

# define KEY_W 0xd
# define KEY_A 0x0
# define KEY_S 0x1
# define KEY_D 0x2
# define KEY_ESC 0x35
# define KEY_SPACE 0x31

typedef struct s_types
{
	char	*textures[4];
	int		floor[3];
	int		ceiling[3];
}	t_types;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		player[2];
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

typedef struct s_player
{
	int	x;
	int	y;
}		t_player;

typedef struct s_core
{
	void		*mlx;
	void		*win;
	int			exit;
	t_img		frame;
	// t_img		textures_varie;
	t_map		map;
	t_types		types;
	t_player	player;
}				t_core;

#endif