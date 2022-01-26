#ifndef CUB3D_H
# define CUB3D_H

# define FALSE 0
# define TRUE 1

/* SYS LIBRARIES */
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>

/* LOCAL LIBRARIES*/
// # include "mlx.h"
# include "libft.h"

/* SUB_HEADERS */
# include <cube_utils.h>
# include <cube_parser.h>

enum e_world {
	SPACE = 32,
	FLOOR = 48,
	WALL,
	NORTH,
	SOUTH,
	EAST,
	WEST,
};

#endif