/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:25:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/11 16:19:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_checker.h"

bool				can_go(t_direction dir, t_cell *cells,
						t_neighbors neighbors);
int					go_up(t_maze maze, t_coordinates player_position);
int					go_down(t_maze maze, t_coordinates player_position);
int					go_left(t_maze maze, t_coordinates player_position);
int					go_right(t_maze maze, t_coordinates player_position);

static t_cell		*init_cells(t_map *map);
int					walk_around(t_maze maze, t_coordinates player_position);
static t_neighbors	calculate_neighbors(t_coordinates cur_pos,
						t_dimensions maze_d);

/**
*	Takes a map and a player position on the map
	and checks whether player is able to collect
	all of the collectables:
	@param map: a valid map
	@param player_position: player position
	@retval 1: map has a valid path
	@retval 0: map does NOT have a valid path
	@retval -1: on errors
*/
int	has_valid_path(t_map *map, t_coordinates player_position)
{
	t_maze	maze;
	int		collectibles_count;

	maze.dimensions.height = map->rows_count;
	maze.dimensions.width = map->columns_count;
	maze.cells = init_cells(map);
	if (!maze.cells)
		return (-1);
	collectibles_count = walk_around(maze, player_position);
	free(maze.cells);
	if (collectibles_count == map->collectibles_count)
		return (1);
	return (0);
}

static t_cell	*init_cells(t_map *map)
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

int	walk_around(t_maze maze, t_coordinates player_position)
{
	t_cell		*cells;
	int			cur_pos;
	t_neighbors	neighbors;
	int			collectables_count;

	cells = maze.cells;
	collectables_count = 0;
	cur_pos = player_position.y * maze.dimensions.width + player_position.x;
	cells[cur_pos].is_visited = true;
	if (cells[cur_pos].value == 'C')
		collectables_count++;
	neighbors = calculate_neighbors(player_position, maze.dimensions);
	if (can_go(UP, cells, neighbors))
		collectables_count += go_up(maze, player_position);
	if (can_go(RIGHT, cells, neighbors))
		collectables_count += go_right(maze, player_position);
	if (can_go(DOWN, cells, neighbors))
		collectables_count += go_down(maze, player_position);
	if (can_go(LEFT, cells, neighbors))
		collectables_count += go_left(maze, player_position);
	return (collectables_count);
}

/**
 * @param cur_pos current position in the maze
 * @param maze_d maze dimensions: width and height
 * @return neighbors structure consisting of 4 indices of the neighbors
 */
static t_neighbors	calculate_neighbors(t_coordinates cur_pos,
		t_dimensions maze_d)
{
	t_neighbors	neighbors;
	int			x;
	int			y;
	int			i;

	x = cur_pos.x;
	y = cur_pos.y;
	i = maze_d.width * y + x;
	neighbors.top = i;
	neighbors.right = i;
	neighbors.bottom = i;
	neighbors.left = i;
	if (y > 0)
		neighbors.top = i - maze_d.width;
	if (x < maze_d.width - 1)
		neighbors.right = i + 1;
	if (y < maze_d.height - 1)
		neighbors.bottom = i - maze_d.width;
	if (x > 0)
		neighbors.left = i - 1;
	return (neighbors);
}
