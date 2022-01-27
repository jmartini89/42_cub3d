#ifndef CUBE_PARSER_H
# define CUBE_PARSER_H

# define SPACE ' '
# define FLOOR '0'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'

void	ft_parser_init(t_map *map, char *arg);
void	ft_types(int fd, t_map *map);
void	ft_map_read(int fd, t_map *map);
void	ft_map_check(t_map *map);

#endif