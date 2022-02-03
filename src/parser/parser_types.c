#include <cub3d.h>
#include <cube_errors.h>
#include <cube_parser.h>
#include <cube_utils.h>

static void
	ft_assign_rgb(char **args, int *type, int index)
{
	int	i;

	if (type[0] != -1)
		ft_fail("TEMP");
	i = -1;
	while (++i < 3)
		type[i] = 0;
	free(args[index]);
}

static void
	ft_assign_texture(t_map *map, int tex_ind, char *path)
{
	if (map->types.textures[tex_ind])
		ft_fail("TEST");
	ft_is_valid_path(path);
	map->types.textures[tex_ind] = path;
}

static int
	ft_check_types_parsed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!map->types.textures[i])
			return (FALSE);
	i = -1;
	while (++i < 3)
		if (map->types.floor[i] == -1 || map->types.ceiling[i] == -1)
			return (FALSE);
	return (TRUE);
}

static int
	ft_check_arg(char *str)
{
	if (!ft_memcmp(str, "NO", strlen(str)))
		return (N_TEX);
	if (!ft_memcmp(str, "SO", strlen(str)))
		return (S_TEX);
	if (!ft_memcmp(str, "EA", strlen(str)))
		return (E_TEX);
	if (!ft_memcmp(str, "WE", strlen(str)))
		return (W_TEX);
	if (!ft_memcmp(str, "F", strlen(str)))
		return (F_TEX);
	if (!ft_memcmp(str, "C", strlen(str)))
		return (C_TEX);
	return (-1);
}

static void
	ft_parse_type(char **args, t_map *map, int index)
{
	int	texture;

	texture = ft_check_arg(args[index]);
	if (texture < 0)
		ft_fail(ERR_PARSE_TYPE);
	if (texture < F_TEX)
		ft_assign_texture(map, texture, args[index + 1]);
	if (texture == F_TEX)
		ft_assign_rgb(args, map->types.floor, index + 1);
	if (texture == C_TEX)
		ft_assign_rgb(args, map->types.ceiling, index + 1);
}

static void
	ft_read_args(t_map *map, char **args)
{
	int	i;

	if (!ft_split_cnt(args))
		return ;
	i = 0;
	while (args[i])
	{
		ft_parse_type(args, map, i);
		free(args[i]);
		if (args[i + 1] && args[i + 2])
			i = +2;
		else
			break ;
	}
	free(args);
}

void
	ft_types_read(int fd, t_map *map)
{
	int		ret;
	char	*line;
	char	**split;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		split = ft_split(line, SPACE);
		if (split == NULL)
			ft_fail(strerror(errno));
		free(line);
		if (ft_split_cnt(split) % 2)
			ft_fail(ERR_PARSE_TYPE_ARGS_LINE);
		ft_read_args(map, split);
		if (ft_check_types_parsed(map))
			return ;
	}
	ft_fail(ERR_PARSE_TYPE_ARGS); // DOES THIS EVEN OCCUR?!
}
