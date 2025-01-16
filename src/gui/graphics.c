/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:23:04 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:14:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static void	draw_cell(char cell_value, int x, int y, t_data *data);
static void	draw_sprite(t_client *user, t_image sprite, int x, int y);

void	draw_map(t_data *data)
{
	char	**cells;
	int		width;
	int		height;
	int		x;
	int		y;

	width = data->game->map->columns_count;
	height = data->game->map->rows_count;
	cells = data->game->map->rows;
	y = -1;
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			draw_cell(cells[y][x], x, y, data);
	}
}

static void	draw_cell(char cell_value, int x, int y, t_data *data)
{
	t_point	cell;

	if (cell_value == '0')
		draw_sprite(data->user, data->assets->ground, x, y);
	else if (cell_value == 'C')
		draw_sprite(data->user, data->assets->collectible, x, y);
	else if (cell_value == 'P')
	{
		draw_sprite(data->user, data->assets->player, x, y);
		cell.x = x * SPRITE_WIDTH;
		cell.y = y * SPRITE_HEIGHT;
		data->game->old_player_position = cell;
		data->game->player_position = cell;
	}
	else if (cell_value == 'E')
		draw_sprite(data->user, data->assets->exit, x, y);
	else if (cell_value == '1')
		draw_sprite(data->user, data->assets->wall, x, y);
}

static void	draw_sprite(t_client *user, t_image sprite, int x, int y)
{
	mlx_put_image_to_window(user->display, user->window, sprite, x
		* SPRITE_WIDTH, y * SPRITE_HEIGHT);
}

void	print_movements_count(t_data *data)
{
	// int	x;
	// int	y;
	// char	*message;
	// char	*count_string;
	// (void)data;
	// count_string = ft_itoa(data->game->movements_count);
	// message = ft_strjoin("Movements count: ", count_string);
	// free(count_string);
	// x = SPRITE_HEIGHT * 5 / 2;
	// y = 10 + 5 * SPRITE_HEIGHT + 20;
	// mlx_clear_window(data->user->display, data->user->window);
	// mlx_string_put(data->user->display, data->user->window, x, y, 0xFFFFFF,
	// 	message);
	// free(message);
	ft_printf("\033[H\033[JMovements count: %d\n", data->game->movements_count);
}

void	update_player_position(t_data *data)
{
	t_image	player;
	t_image	ground;
	t_point	old_pos;
	t_point	new_pos;

	player = data->assets->player;
	ground = data->assets->ground;
	old_pos = data->game->old_player_position;
	new_pos = data->game->player_position;
	mlx_put_image_to_window(data->user->display, data->user->window, ground,
		old_pos.x, old_pos.y);
	mlx_put_image_to_window(data->user->display, data->user->window, player,
		new_pos.x, new_pos.y);
}
