/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:27:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:02:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H

# include "map.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct point
{
	int		x;
	int		y;
}			t_point;

typedef struct game_data
{
	t_map	*map;
	int		movements_count;
	int		collected_count;
	t_point	player_position;
	t_point	old_player_position;
	bool	game_over;
}			t_game_data;

t_game_data	*init_game_data(t_map *map);
void		free_game_data(t_game_data *game_data);

#endif