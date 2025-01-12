/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_toolkit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:15:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 15:17:42 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_toolkit.h"

static void	free_data(t_map *map, t_map_data *map_data,
				t_map_errors *map_errors);
static void	print_failure(char *str);
// static void	print_success(char *str);

int	process_map(char *filepath)
{
	t_map			*map;
	t_map_errors	*map_errors;
	t_map_data		*map_data;
	bool			has_errors;

	map = parse_map(filepath);
	if (!map)
		return (perror(""), MAP_INIT_ERROR);
	map_data = analyze_map(map);
	if (!map_data)
		return (perror(""), MAP_DATA_INIT_ERROR);
	map_errors = collect_map_errors(map_data);
	if (!map_errors)
		return (perror(""), MAP_ERRORS_INIT_ERROR);
	has_errors = map_errors->count > 0;
	if (has_errors)
		print_map_errors(map_errors);
	if (!has_errors && !has_valid_path(map, map_data->player_position))
	{
		has_errors = true;
		print_failure("The map doesn't have a valid path");
	}
	free_data(map, map_data, map_errors);
	return (0);
}
// if (!has_errors)
// 	print_success("The map is valid");

static void	free_data(t_map *map, t_map_data *map_data,
		t_map_errors *map_errors)
{
	if (map)
		free_map(&map);
	if (map_data)
		free(map_data);
	if (map_errors)
		free(map_errors);
}

// static void	print_success(char *str)
// {
// 	ft_printf("\033[0;32m%s ✅\n\033[0m", str);
// }

static void	print_failure(char *str)
{
	ft_printf("\033[31mError\n%s ❌\n\033[0m", str);
}
