/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:54:23 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/19 18:17:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

int		handle_key_pressed(int keysym, t_data *data);
int		render(t_data *data);
int		close_window(t_data *data);

void	subscribe_to_events(t_client *user, t_data *data)
{
	mlx_hook(user->window, KeyPress, KeyPressMask, handle_key_pressed, data);
	mlx_hook(user->window, DestroyNotify, StructureNotifyMask, close_window,
		data);
	mlx_loop_hook(user->display, render, data);
}

void	listen_for_events(t_client *user)
{
	mlx_loop(user->display);
}

int	handle_key_pressed(int keysym, t_data *data)
{
	t_direction	direction;

	if (keysym == XK_Escape)
		close_window(data);
	if (!data->game->game_over && is_movement_key(keysym))
	{
		direction = 0;
		if (keysym == KEY_LEFT)
			direction = LEFT;
		else if (keysym == KEY_RIGHT)
			direction = RIGHT;
		else if (keysym == KEY_UP)
			direction = UP;
		else if (keysym == KEY_DOWN)
			direction = DOWN;
		if (can_player_go(direction, data->game))
			player_go(direction, data->game);
	}
	return (0);
}

int	render(t_data *data)
{
	int	x;
	int	y;

	if (is_player_position_changed(data->game))
	{
		update_graphic_player_position(data);
		data->game->old_player_position = data->game->player_position;
		print_movements_count(data);
		if (data->game->game_over)
		{
			x = data->user->dimensions.width / 2 - 10;
			y = data->user->dimensions.height / 2 + 10;
			mlx_clear_window(data->user->display, data->user->window);
			mlx_string_put(data->user->display, data->user->window, x, y,
				0xFF0000, "WIN");
		}
	}
	return (0);
}

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
}
