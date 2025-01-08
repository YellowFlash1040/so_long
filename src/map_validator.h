#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

# include <stdbool.h>
# include <stdlib.h>

typedef struct map_data
{
	int		columns_count;
	int		rows_count;
	bool	is_a_rectangle;
	bool	has_duplicates;
	bool	has_invalid_chars;
	bool	has_enough_components;
	bool	is_surrouded_by_walls;
	bool	has_a_valid_path;
}			t_map_data;

bool		is_valid_map(char **map);

#endif