/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 12:42:15 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DATA_H
# define MAP_DATA_H

# include "map.h"
# include <stdbool.h>

typedef struct map_data
{
	t_map			*map;
	bool			is_a_rectangle;
	bool			has_invalid_chars;
	bool			is_surrouded_by_walls;
	int				players_count;
	int				collectibles_count;
	int				exits_count;
	t_coordinates	player_position;
}					t_map_data;

t_map_data			*init_map_data(t_map *map);

#endif