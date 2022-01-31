#ifndef CUBE_PARSER_H
# define CUBE_PARSER_H

# define SPACE ' '
# define FLOOR '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

typedef struct s_types
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
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
void	ft_types(int fd, t_map *map);
void	ft_map_read(int fd, t_map *map);
void	ft_map_check(t_map *map);

#endif