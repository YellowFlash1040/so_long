/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:57:35 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:03:18 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_data.h"

t_game_data	*init_game_data(t_map *map)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!game_data)
		return (NULL);
	game_data->map = map;
	game_data->movements_count = 0;
	game_data->collected_count = 0;
	game_data->game_over = false;
	return (game_data);
}

void	free_game_data(t_game_data *game_data)
{
	free_map(&game_data->map);
	free(game_data);
}
