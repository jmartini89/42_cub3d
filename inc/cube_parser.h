#ifndef CUBE_PARSER_H
# define CUBE_PARSER_H

/*
* MAP CHARS
*/
# define SPACE ' '
# define FLOOR '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

/*
* TEXTURE PATH INDEX
*/
enum e_textures {
	N_TEX,
	S_TEX,
	E_TEX,
	W_TEX,
	F_TEX,
	C_TEX
};

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
	t_types	types;
}	t_map;

void	ft_parser(t_map *map, char *arg);

void	ft_types_read(int fd, t_map *map);
void	ft_types_args(t_map *map, char **args);

void	ft_map_read(int fd, t_map *map);
void	ft_map_check(t_map *map);

int		ft_split_cnt(char **split);
void	ft_is_valid_path(char *path);

#endif