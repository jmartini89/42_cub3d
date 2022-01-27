#ifndef CUBE_UTILS_H
# define CUBE_UTILS_H



typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		player[2];
}	t_map;

void	ft_fail(char *str);
int		get_next_line(int fd, char **line);

#endif