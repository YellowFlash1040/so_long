/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:25:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 18:45:44 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "path_checker.h"
#include <stdio.h>

t_cell		*init_cells(t_map *map);
int			walk_around(t_maze maze, t_cell player_position);
t_neighbors	calculate_neighbors(t_maze maze, t_cell current_cell);
t_cell		get_cell(t_maze maze, int x, int y);
int			go_up(t_maze maze, t_cell player_position);
int			go_down(t_maze maze, t_cell player_position);
int			go_left(t_maze maze, t_cell player_position);
int			go_right(t_maze maze, t_cell player_position);
t_cell		find_player_position(t_map *map);
// t_cell		find_start_position(t_cell cell);
// t_cell		find_end_position(t_cell cell, t_dimensions map_dimensions);
// void	print_cells(t_cell *cells, t_dimensions arr_dimensions);

/*
Takes a map and returns:
1 - if map has a valid path
0 - if map does NOT have a valid path
-1 - on error
*/
int	has_valid_path(t_map *map)
{
	t_cell	player_position;
	t_maze	maze;
	int		collectibles_count;

	player_position = find_player_position(map);
	if (player_position.value == '2')
		return (-1);
	maze.dimensions.height = map->rows_count;
	maze.dimensions.width = map->columns_count;
	maze.cells = init_cells(map);
	if (!maze.cells)
		return (-1);
	collectibles_count = walk_around(maze, player_position);
	if (collectibles_count == map->collectibles_count)
		return (1);
	return (0);
}

t_cell	find_player_position(t_map *map)
{
	t_cell	player_position;
	int		x;
	int		y;

	player_position.x = -1;
	player_position.y = -1;
	player_position.is_visited = false;
	player_position.value = '2';
	y = -1;
	while (++y < map->rows_count)
	{
		x = index_of('P', map->rows[y]);
		if (x != -1)
		{
			player_position.x = x;
			player_position.y = y;
			player_position.is_visited = false;
			player_position.value = 'P';
			return (player_position);
		}
	}
	return (player_position);
}

t_cell	*init_cells(t_map *map)
{
	t_cell	*cells;
	int		y;
	int		x;
	int		i;

	cells = (t_cell *)malloc(sizeof(t_cell) * (map->rows_count
				* map->columns_count));
	if (!cells)
		return (NULL);
	i = 0;
	y = -1;
	while (++y < map->rows_count)
	{
		x = -1;
		while (++x < map->columns_count)
		{
			cells[i].value = map->rows[y][x];
			cells[i].is_visited = false;
			cells[i].x = x;
			cells[i].y = y;
			i++;
		}
	}
	return (cells);
}

int	walk_around(t_maze maze, t_cell player_position)
{
	int			current_cell_index;
	t_neighbors	neighbors;
	int			collectables_count;

	collectables_count = 0;
	current_cell_index = player_position.y * maze.dimensions.width
		+ player_position.x;
	maze.cells[current_cell_index].is_visited = true;
	if (maze.cells[current_cell_index].value == 'C')
		collectables_count++;
	neighbors = calculate_neighbors(maze, player_position);
	if (neighbors.top.value != '1' && !get_cell(maze, neighbors.top.x,
			neighbors.top.y).is_visited)
		collectables_count += go_up(maze, player_position);
	if (neighbors.right.value != '1' && !get_cell(maze, neighbors.right.x,
			neighbors.right.y).is_visited)
		collectables_count += go_right(maze, player_position);
	if (neighbors.bottom.value != '1' && !get_cell(maze, neighbors.bottom.x,
			neighbors.bottom.y).is_visited)
		collectables_count += go_down(maze, player_position);
	if (neighbors.left.value != '1' && !get_cell(maze, neighbors.left.x,
			neighbors.left.y).is_visited)
		collectables_count += go_left(maze, player_position);
	if (maze.cells[current_cell_index].value == 'C')
		return (collectables_count);
	return (collectables_count);
}

t_neighbors	calculate_neighbors(t_maze maze, t_cell current_cell)
{
	t_neighbors	neighbors;
	int			x;
	int			y;

	x = current_cell.x;
	y = current_cell.y;
	neighbors.top = get_cell(maze, x, y);
	neighbors.right = get_cell(maze, x, y);
	neighbors.bottom = get_cell(maze, x, y);
	neighbors.left = get_cell(maze, x, y);
	if (current_cell.y > 0)
		neighbors.top = get_cell(maze, x, y - 1);
	if (current_cell.x < maze.dimensions.width - 1)
		neighbors.right = get_cell(maze, x + 1, y);
	if (current_cell.y < maze.dimensions.height - 1)
		neighbors.bottom = get_cell(maze, x, y + 1);
	if (current_cell.x > 0)
		neighbors.left = get_cell(maze, x - 1, y);
	return (neighbors);
}

t_cell	get_cell(t_maze maze, int x, int y)
{
	int	index;

	index = maze.dimensions.width * y + x;
	return (maze.cells[index]);
}

int	go_up(t_maze maze, t_cell player_position)
{
	player_position.y--;
	return (walk_around(maze, player_position));
}

int	go_down(t_maze maze, t_cell player_position)
{
	player_position.y++;
	return (walk_around(maze, player_position));
}

int	go_left(t_maze maze, t_cell player_position)
{
	player_position.x--;
	return (walk_around(maze, player_position));
}

int	go_right(t_maze maze, t_cell player_position)
{
	player_position.x++;
	return (walk_around(maze, player_position));
}

// t_cell	find_start_position(t_cell cell)
// {
// 	t_cell	start_position;

// 	if (cell.x == 0)
// 		start_position.x = 0;
// 	else
// 		start_position.x = cell.x - 1;
// 	if (cell.y == 0)
// 		start_position.y = cell.y;
// 	else
// 		start_position.y = cell.y - 1;
// 	return (start_position);
// }

// t_cell	find_end_position(t_cell cell, t_dimensions map_dimensions)
// {
// 	t_cell	end_position;

// 	if (cell.x == map_dimensions.width - 1)
// 		end_position.x = cell.x;
// 	else
// 		end_position.x = cell.x + 1;
// 	if (cell.y == map_dimensions.height - 1)
// 		end_position.y = cell.y;
// 	else
// 		end_position.y = cell.y + 1;
// 	return (end_position);
// }

// void	print_cells(t_cell *cells, t_dimensions arr_dimensions)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	t_cell	cell;

// 	i = 0;
// 	y = -1;
// 	while (++y < arr_dimensions.height)
// 	{
// 		x = -1;
// 		while (++x < arr_dimensions.width)
// 		{
// 			cell = cells[i];
// 			printf("x = %d, y = %d, value = %c;  ", cell.x, cell.y, cell.value);
// 			i++;
// 		}
// 		printf("\n");
// 	}
// }

// start_position = find_start_position(player_position);
// end_position = find_end_position(player_position, maze.dimensions);
// current_position = start_position;
// while (current_position.y <= end_position.y)
// {
// 	current_position.x = start_position.x;
// 	while (current_position.x <= end_position.x)
// 	{
// 		i = current_position.y * maze.dimensions.width + current_position.x;
// 		cell_value = maze.cells[i].value;
// 		if (cell_value == '0' || cell_value == 'C')
// 			return (true);
// 		current_position.x++;
// 	}
// 	current_position.y++;
// }
// return (false);

// if (player_position.y > 0)
// {
// 		next_cell = current_cell - maze.dimensions.width;
// 		if (!maze.cells[next_cell].is_visited)
// 			go_up(maze, player_position);
// }
// if (player_position.x < maze.dimensions.width - 1)
// {
// 		go_right(maze, player_position);
// }
// if (player_position.y < maze.dimensions.height - 1)
// {
// 		go_down(maze, player_position);
// }
// if (player_position.x > 0)
// {
// 		go_left(maze, player_position);
// }