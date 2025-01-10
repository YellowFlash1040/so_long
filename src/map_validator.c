#include "map_validator.h"

static bool	analyze_row(t_map_data *map_data, char *row);
static bool	analyze_map(t_map_data *map_data);
static bool	has_valid_cpe_amount(t_map_data *map_data);
static bool	has_holes(t_map *map);

/*
Takes a map and returns:
1 - if map is a valid map
0 - if map is invalid
-1 - on error
*/
int	is_valid_map(t_map *map)
{
	t_map_data	*map_data;
	bool		result;

	if (map->rows_count < 3)
		return (0);
	map->columns_count = ft_strlen(map->rows[0]);
	if (map->columns_count < 5)
		return (0);
	map_data = init_map_data(map);
	if (!map_data)
		return (-1);
	result = 1;
	if (!analyze_map(map_data))
		result = 0;
	else if (!has_valid_cpe_amount(map_data))
		result = 0;
	else if (has_holes(map))
		result = 0;
	free(map_data);
	return (result);
}

/*
Checks whether a map has holes in the:
- roof (first row)
- base (last row)
*/
static bool	has_holes(t_map *map)
{
	if (index_of('0', map->rows[0]) != -1)
		return (true);
	else if (index_of('0', map->rows[map->rows_count - 1]) != -1)
		return (true);
	return (false);
}

/*
Checks whether the map contains:
- at least 1 collectible (C)
- exactly 1 starting position (P)
- exactly 1 exit (E)
*/
static bool	has_valid_cpe_amount(t_map_data *map_data)
{
	if (map_data->exits_count != 1)
		return (false);
	else if (map_data->players_count != 1)
		return (false);
	else if (map_data->map->collectibles_count < 1)
		return (false);
	return (true);
}

/*
Goes through map row by row and:
- checks whether it has invalid characters
- checks whether it has holes in the walls from the sides
- checks whether map is a rectangle
- collects information about the map like:
	- amount of players
	- amount of collectables
	- amount of exits

Doesn't go to the next row if it finds any errors in the current one
*/
static bool	analyze_map(t_map_data *map_data)
{
	t_map	*map;
	int		i;

	map = map_data->map;
	i = -1;
	while (++i < map->rows_count)
		if (!analyze_row(map_data, map->rows[i]))
			return (false);
	return (true);
}

/*
Goes through the row and:
- checks whether it has invalid characters
- checks whether it has holes in the walls from the sides
- checks whether map is a rectangle
- collects information about the map like:
	- amount of players
	- amount of collectables
	- amount of exits
*/
static bool	analyze_row(t_map_data *map_data, char *row)
{
	t_map	*map;
	int		i;

	map = map_data->map;
	if (row[0] == '0')
		map_data->is_surrouded_by_walls = false;
	i = -1;
	while (row[++i])
	{
		if (row[i] == 'C')
			map->collectibles_count++;
		else if (row[i] == 'P')
			map_data->players_count++;
		else if (row[i] == 'E')
			map_data->exits_count++;
		else if (row[i] == '0' && row[i + 1] == '\0')
			map_data->is_surrouded_by_walls = false;
		else if (!(row[i] == '1' || row[i] == '0'))
			return (false);
	}
	if (i != map->columns_count)
		map_data->is_a_rectangle = false;
	return (map_data->is_a_rectangle && map_data->is_surrouded_by_walls);
}
