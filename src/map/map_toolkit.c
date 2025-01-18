/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_toolkit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:15:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/18 17:12:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_toolkit.h"

static int	parse_and_analyze_map(char *filepath, t_map **map,
				t_map_data **map_data);
static int	validate_map(t_map *map, t_map_data *map_data);

int	process_map_file(char *filepath, t_map **map)
{
	t_map_data	*map_data;
	int			status;

	map_data = NULL;
	status = parse_and_analyze_map(filepath, map, &map_data);
	if (status != 0)
		return (free(map_data), status);
	status = validate_map(*map, map_data);
	free(map_data);
	return (status);
}

static int	parse_and_analyze_map(char *filepath, t_map **map,
		t_map_data **map_data)
{
	int	parsing_result;

	parsing_result = parse_map(filepath, map);
	if (parsing_result != 0)
	{
		if (errno != EXIT_SUCCESS)
			perror("");
		else if (parsing_result == EMPTY_FILE_ERR)
			print_failure(EMPTY_FILE_ERR_MSG);
		return (parsing_result);
	}
	*map_data = analyze_map(*map);
	if (!*map_data)
		return (perror(""), MAP_DATA_INIT_ERROR);
	return (0);
}

static int	validate_map(t_map *map, t_map_data *map_data)
{
	t_map_errors	*map_errors;
	int				status;

	map_errors = collect_map_errors(map_data);
	if (!map_errors)
		return (perror(""), MAP_ERRORS_INIT_ERROR);
	status = 0;
	if (map_errors->count > 0)
		status = 1;
	else if (!has_valid_path(map, map_data->player_position))
	{
		status = 1;
		map_errors->has_valid_path = false;
		map_errors->count++;
	}
	if (map_errors->count > 0)
		print_map_errors(map_errors);
	free(map_errors);
	return (status);
}
