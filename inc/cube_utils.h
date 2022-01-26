#ifndef CUBE_UTILS_H
# define CUBE_UTILS_H

# define ERR_GENERIC "Generic"
# define ERR_ARGS "Wrong arguments"
# define ERR_SYS_MALLOC "Malloc"

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}	t_map;

void	ft_fail(char *str);
int		get_next_line(int fd, char **line);

#endif