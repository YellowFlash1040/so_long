#ifndef FILE_H
# define FILE_H

# include "../get_next_line/get_next_line.h"
# include "../list/list.h"
# include "../string/string.h"
# include <fcntl.h>
# include <stdlib.h>

char	*get_file_extension(char *filepath);
char	**read_all_lines(char *filepath);
bool	file_exists(const char *filepath);

#endif