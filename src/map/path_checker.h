/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:25:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:34:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_CHECKER_H
# define PATH_CHECKER_H

# include "dimension.h"
# include "direction.h"
# include "map.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct cell
{
	int				x;
	int				y;
	bool			is_visited;
	char			value;
}					t_cell;

typedef struct maze
{
	t_cell			*cells;
	t_dimensions	dimensions;
}					t_maze;

typedef struct neighbors
{
	int				top;
	int				bottom;
	int				left;
	int				right;
}					t_neighbors;

typedef struct maze_data
{
	int				collectibles_count;
	bool			is_exit_reachable;
}					t_maze_data;

int					has_valid_path(t_map *map, t_coordinates player_position);

#endif