#ifndef CUBE_PARSER_H
# define CUBE_PARSER_H

# define ERR_PARSE_EXT "Bad file extension"

void	ft_parser_init(char *arg);
void	ft_map_read(int fd, char ***map);

#endif