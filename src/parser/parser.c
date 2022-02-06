#include "c3d_libs.h"
#include "c3d_core.h"
#include "c3d_parser.h"
#include "c3d_utils.h"

static void
	ft_check_file_extension(char *arg)
{
	int	len;

	len = strlen(arg);
	if (len < 5 || ft_strncmp(&arg[len - 4], ".cub", 4))
		ft_fail(ERR_PARSE_EXT);
}

static void
	ft_init_args(t_core *core)
{
	int	i;

	core->map.map = NULL;
	core->map.width = 0;
	core->map.height = 0;
	core->map.player[Y] = 0;
	core->map.player[X] = 0;
	i = -1;
	while (++i < 4)
		core->types.textures[i] = NULL;
	i = -1;
	while (++i < 3)
	{
		core->types.floor[i] = -1;
		core->types.ceiling[i] = -1;
	}
}

void
	ft_parser(t_core *core, char *arg)
{
	int		fd;

	ft_check_file_extension(arg);
	ft_init_args(core);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_fail(strerror(errno));
	ft_types_read(fd, &core->types);
	ft_map_read(fd, &core->map);
	close(fd);
	ft_map_check(&core->map);

	int i = -1;
	while (++i < 3)
		printf("%d ", core->types.floor[i]);
	printf("\n");
	i = -1;
	while (++i < 3)
		printf("%d ", core->types.ceiling[i]);
	printf("\n");
	i = -1;
	while (++i < 4)
		printf("%s\n", core->types.textures[i]);
}
