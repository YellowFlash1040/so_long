/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:56:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 15:17:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	start_game(t_map *map)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->user = create_window(map->columns_count * SPRITE_WIDTH,
			map->rows_count * SPRITE_HEIGHT + 30, TITLE);
	if (!data->user)
		return (free_data(data), 1);
	data->assets = load_assets(data->user->display);
	if (!data->assets)
		return (free_data(data), 1);
	data->game = init_game_data(map);
	if (!data->game)
		return (free_data(data), 1);
	draw_map(data);
	subscribe_to_events(data->user, data);
	listen_for_events(data->user);
	return (0);
}
