#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "../libraries/file/file.h"
# include "../libraries/string/string.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

bool	parse_map(char *filePath);

#endif