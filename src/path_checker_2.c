/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:15:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/11 16:54:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_checker.h"

int		walk_around(t_maze maze, t_coordinates player_position);

bool	can_go(t_direction dir, t_cell *cells, t_neighbors neighbors)
{
	t_cell	neighbor;

	if (dir == UP)
		neighbor = cells[neighbors.top];
	else if (dir == DOWN)
		neighbor = cells[neighbors.bottom];
	else if (dir == LEFT)
		neighbor = cells[neighbors.left];
	else if (dir == RIGHT)
		neighbor = cells[neighbors.right];
	else
		return (false);
	if (neighbor.value != '1' && !neighbor.is_visited)
		return (true);
	return (false);
}

int	go_up(t_maze maze, t_coordinates player_position)
{
	player_position.y--;
	return (walk_around(maze, player_position));
}

int	go_down(t_maze maze, t_coordinates player_position)
{
	player_position.y++;
	return (walk_around(maze, player_position));
}

int	go_left(t_maze maze, t_coordinates player_position)
{
	player_position.x--;
	return (walk_around(maze, player_position));
}

int	go_right(t_maze maze, t_coordinates player_position)
{
	player_position.x++;
	return (walk_around(maze, player_position));
}
