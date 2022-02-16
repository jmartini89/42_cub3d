/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm & mc <jmartini & mcrisari>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:11:33 by jm & mc           #+#    #+#             */
/*   Updated: 2022/02/16 15:11:34 by jm & mc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C3D_UTILS_H
# define C3D_UTILS_H

# include "c3d_core.h"

# define ERR_GENERIC "Generic"

# define ERR_GNL "Get Next Line: bad (FD || ADDRESS || MALLOC)"
# define ERR_PARSE_EXT "Bad file extension"
# define ERR_PARSE_MAP "Parsing: Not a valid map"
# define ERR_PARSE_CHAR "Parsing: Not a valid map element"
# define ERR_PARSE_SPAWN "Parsing: Not a valid spawn"
# define ERR_PARSE_TYPE "Parsing: Not a valid type"
# define ERR_PARSE_TYPE_ARGS_LINE "Parsing: Wrong number of type args in line"
# define ERR_PARSE_TYPE_ARGS "Parsing: Wrong number of type arguments"
# define ERR_PARSE_TYPE_MULTI "Parsing: multiple initializations of same type"
# define ERR_PARSE_TYPE_RGB_STR "Parsing: Ceiling/Floor wrong RGB string"
# define ERR_PARSE_TYPE_RGB_VAL "Parsing: Ceiling/Floor wrong RGB value"
# define ERR_MLX_INIT "MLX: Connection to display failed"
# define ERR_MLX_WIN "MLX: Creation of new window failed"
# define ERR_MLX_IMG "MLX: IMG initialization failed"
# define ERR_MLX_XPM "MLX: XPM to IMG load failed"

int		get_next_line(int fd, char **line);
void	ft_fail(char *str);
void	ft_exit(t_core *core);

#endif