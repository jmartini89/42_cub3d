#ifndef C3D_PARSER_H
# define C3D_PARSER_H

# include "c3d_core.h"

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

void	ft_parser(t_core *core, char *arg);

void	ft_types_read(int fd, t_types *types);
void	ft_types_args(t_types *types, char **args);

void	ft_map_read(int fd, t_map *map);
void	ft_map_check(t_map *map);

int		ft_split_cnt(char **split);
void	ft_is_valid_path(char *path);

#endif