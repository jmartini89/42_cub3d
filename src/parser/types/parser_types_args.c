#include <cub3d.h>
#include <cube_errors.h>
#include <cube_parser.h>
#include <cube_utils.h>

static void
	ft_assign_rgb(int *type, char *arg)
{
	int		i;
	char	**rgb;

	if (type[0] != -1)
		ft_fail(ERR_PARSE_TYPE_MULTI);
	rgb = ft_split(arg, ',');
	if (rgb == NULL)
		ft_fail(strerror(errno));
	if (ft_split_cnt(rgb) != 3)
		ft_fail(ERR_PARSE_TYPE_RGB_STR);
	i = -1;
	while (++i < 3)
	{
		type[i] = ft_atoi(rgb[i]);
		free(rgb[i]);
		if (type[i] < 0 || type[i] > 255)
			ft_fail(ERR_PARSE_TYPE_RGB_VAL);
	}
	free(rgb);
	free(arg);
}

static void
	ft_assign_texture(t_types *types, int tex_ind, char *path)
{
	if (types->textures[tex_ind])
		ft_fail(ERR_PARSE_TYPE_MULTI);
	ft_is_valid_path(path);
	types->textures[tex_ind] = path;
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
	ft_parse_type(char **args, t_types *types, int index)
{
	int	texture;

	texture = ft_check_arg(args[index]);
	if (texture < 0)
		ft_fail(ERR_PARSE_TYPE);
	if (texture < F_TEX)
		ft_assign_texture(types, texture, args[index + 1]);
	if (texture == F_TEX)
		ft_assign_rgb(types->floor, args[index + 1]);
	if (texture == C_TEX)
		ft_assign_rgb(types->ceiling, args[index + 1]);
}

void
	ft_types_args(t_types *types, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_split_cnt(args))
			break ;
		ft_parse_type(args, types, i);
		free(args[i]);
		if (args[i + 1] && args[i + 2])
			i += 2;
		else
			break ;
	}
	free(args);
}