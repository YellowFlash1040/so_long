/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 13:40:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_checker.h"

t_maze_data	walk_around(t_maze maze, t_coordinates player_position);

t_maze_data	go_up(t_maze maze, t_coordinates player_position)
{
	player_position.y--;
	return (walk_around(maze, player_position));
}

t_maze_data	go_down(t_maze maze, t_coordinates player_position)
{
	player_position.y++;
	return (walk_around(maze, player_position));
}

t_maze_data	go_left(t_maze maze, t_coordinates player_position)
{
	player_position.x--;
	return (walk_around(maze, player_position));
}

t_maze_data	go_right(t_maze maze, t_coordinates player_position)
{
	player_position.x++;
	return (walk_around(maze, player_position));
}

bool	is_obstacle(char cell_value)
{
	if (cell_value == '0')
		return (false);
	else if (cell_value == 'C')
		return (false);
	return (true);
}
