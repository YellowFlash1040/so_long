/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_analyzer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:34:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 14:13:53 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_analyzer.h"

static void	analyze_row(t_map_data *map_data, int row_index);
static void	analyze_cell(t_map_data *map_data, t_coordinates cell_p);
static void	check_for_holes(t_map_data *map_data);

t_map_data	*analyze_map(t_map *map)
{
	t_map_data	*map_data;
	int			i;

	map_data = init_map_data(map);
	if (!map_data)
		return (NULL);
	map_data->map = map;
	i = -1;
	while (++i < map->rows_count)
		analyze_row(map_data, i);
	map->collectibles_count = map_data->collectibles_count;
	check_for_holes(map_data);
	return (map_data);
}

static void	analyze_row(t_map_data *map_data, int row_index)
{
	t_map			*map;
	char			*row;
	t_coordinates	cell;

	row = map_data->map->rows[row_index];
	if (row[0] == '0')
		map_data->is_surrouded_by_walls = false;
	cell.y = row_index;
	cell.x = -1;
	while (row[++cell.x])
		analyze_cell(map_data, cell);
	if (row[cell.x - 1] == '0')
		map_data->is_surrouded_by_walls = false;
	map = map_data->map;
	if (cell.x != map->columns_count)
		map_data->is_a_rectangle = false;
}

// cell_p - stands for cell position
static void	analyze_cell(t_map_data *map_data, t_coordinates cell_p)
{
	char	cell_value;

	cell_value = map_data->map->rows[cell_p.y][cell_p.x];
	if (cell_value == 'C')
		map_data->collectibles_count++;
	else if (cell_value == 'P')
	{
		map_data->players_count++;
		map_data->player_position = cell_p;
	}
	else if (cell_value == 'E')
		map_data->exits_count++;
	else if (!(cell_value == '1' || cell_value == '0'))
		map_data->has_invalid_chars = true;
}

// checks for the holes in the roof and the base
static void	check_for_holes(t_map_data *map_data)
{
	t_map	*map;

	if (!map_data->is_surrouded_by_walls)
		return ;
	map = map_data->map;
	if (index_of('0', map->rows[0]) != -1)
		map_data->is_surrouded_by_walls = false;
	else if (index_of('0', map->rows[map->rows_count - 1]) != -1)
		map_data->is_surrouded_by_walls = false;
}
