#ifndef CUBE_PARSER_H
# define CUBE_PARSER_H

# define ERR_PARSE_EXT "Bad file extension"

void	ft_parser_init(t_map *map, char *arg);
void	ft_map_read(int fd, t_map *map);

#endif