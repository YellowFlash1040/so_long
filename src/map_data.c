/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:36 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 18:26:37 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_data.h"

t_map_data	*init_map_data(t_map *map)
{
	t_map_data	*map_data;

	map_data = (t_map_data *)malloc(sizeof(t_map_data));
	if (!map_data)
		return (NULL);
	map_data->map = map;
	map_data->exits_count = 0;
	map_data->players_count = 0;
	map_data->has_a_valid_path = true;
	map_data->has_duplicates = false;
	map_data->has_enough_components = true;
	map_data->has_invalid_chars = false;
	map_data->is_a_rectangle = true;
	map_data->is_surrouded_by_walls = true;
	return (map_data);
}
