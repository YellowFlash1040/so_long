/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 12:36:05 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_err_collector.h"

static bool		has_minimum_dimensions(int map_width, int map_height);
static bool		has_valid_cpe_amount(t_map_data *map_data);

t_map_errors	*collect_map_errors(t_map_data *map_data)
{
	t_map_errors	*map_errors;
	int				map_width;
	int				map_height;

	map_errors = init_map_errors();
	if (!map_errors)
		return (NULL);
	map_width = map_data->map->columns_count;
	map_height = map_data->map->rows_count;
	map_errors->has_holes = !map_data->is_surrouded_by_walls;
	map_errors->has_invalid_chars = map_data->has_invalid_chars;
	map_errors->has_minimum_dimensions = has_minimum_dimensions(map_width,
			map_height);
	map_errors->has_valid_cpe_amount = has_valid_cpe_amount(map_data);
	map_errors->is_a_rectangle = map_data->is_a_rectangle;
	map_errors->count = count_errors(map_errors);
	return (map_errors);
}

static bool	has_minimum_dimensions(int map_width, int map_height)
{
	if (map_width >= 3 && map_height >= 5)
		return (true);
	if (map_width >= 5 && map_height >= 3)
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
	else if (map_data->collectibles_count < 1)
		return (false);
	return (true);
}
