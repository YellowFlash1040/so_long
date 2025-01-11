/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:25:59 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 18:26:00 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_CHECKER_H
# define PATH_CHECKER_H

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

typedef struct dimensions
{
	int				width;
	int				height;
}					t_dimensions;

typedef struct maze
{
	t_cell			*cells;
	t_dimensions	dimensions;
}					t_maze;

typedef struct neighbors
{
	t_cell			top;
	t_cell			bottom;
	t_cell			left;
	t_cell			right;
}					t_neighbors;

typedef struct coordinates
{
	int				x;
	int				y;
}					t_coordinates;

int					has_valid_path(t_map *map);

#endif