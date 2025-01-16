/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:21:02 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:29:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"
#include "path_checker.h"
#include "sprite.h"

bool	can_player_go(t_direction direction, t_game_data *game_data)
{
	char	**cells;
	int		x;
	int		y;

	cells = game_data->map->rows;
	x = game_data->player_position.x / SPRITE_WIDTH;
	y = game_data->player_position.y / SPRITE_HEIGHT;
	if (direction == LEFT)
		x--;
	else if (direction == RIGHT)
		x++;
	else if (direction == UP)
		y--;
	else if (direction == DOWN)
		y++;
	if (cells[y][x] == '1')
		return (false);
	else if (cells[y][x] == 'E'
		&& game_data->collected_count != game_data->map->collectibles_count)
		return (false);
	return (true);
}

void	player_go(t_direction direction, t_game_data *game_data)
{
	char	**cells;
	int		x;
	int		y;

	cells = game_data->map->rows;
	if (direction == LEFT)
		game_data->player_position.x -= STEP;
	else if (direction == RIGHT)
		game_data->player_position.x += STEP;
	else if (direction == UP)
		game_data->player_position.y -= STEP;
	else if (direction == DOWN)
		game_data->player_position.y += STEP;
	game_data->movements_count++;
	x = game_data->player_position.x / SPRITE_WIDTH;
	y = game_data->player_position.y / SPRITE_HEIGHT;
	if (cells[y][x] == 'C')
	{
		cells[y][x] = '0';
		game_data->collected_count++;
	}
	else if (cells[y][x] == 'E')
		game_data->game_over = true;
}

bool	is_player_position_changed(t_game_data *game_data)
{
	t_point	player_position;
	t_point	old_player_position;

	player_position = game_data->player_position;
	old_player_position = game_data->old_player_position;
	if (player_position.x != old_player_position.x
		|| player_position.y != old_player_position.y)
		return (true);
	return (false);
}

bool	is_movement_key(int keysym)
{
	if (keysym == KEY_LEFT)
		return (true);
	else if (keysym == KEY_RIGHT)
		return (true);
	else if (keysym == KEY_UP)
		return (true);
	else if (keysym == KEY_DOWN)
		return (true);
	return (false);
}
