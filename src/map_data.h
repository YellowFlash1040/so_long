/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 18:26:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

# include "map.h"
# include <stdbool.h>

typedef struct map_data
{
	t_map	*map;
	bool	is_a_rectangle;
	bool	has_duplicates;
	bool	has_invalid_chars;
	bool	has_enough_components;
	bool	is_surrouded_by_walls;
	bool	has_a_valid_path;
	int		players_count;
	int		exits_count;
}			t_map_data;

t_map_data	*init_map_data(t_map *map);

#endif