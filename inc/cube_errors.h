#ifndef CUBE_ERRORS_H
# define CUBE_ERRORS_H

# define ERR_GENERIC "Generic"

# define ERR_PARSE_EXT "Bad file extension"
# define ERR_PARSE_MAP "Parsing: Not a valid map"
# define ERR_PARSE_SPAWN "Parsing: Not a valid spawn"
# define ERR_PARSE_TYPE "Parsing: Not a valid type"
# define ERR_PARSE_TYPE_ARGS_LINE "Parsing: Wrong number of type args in line"
# define ERR_PARSE_TYPE_ARGS "Parsing: Wrong number of type arguments"
# define ERR_PARSE_TYPE_MULTI "Parsing: multiple initializations of same type"
# define ERR_PARSE_TYPE_RGB_STR "Parsing: Ceiling/Floor wrong RGB string"
# define ERR_PARSE_TYPE_RGB_VAL "Parsing: Ceiling/Floor wrong RGB value"

void	ft_fail(char *str);

#endif