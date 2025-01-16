/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:21:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/14 15:17:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERRORS_H
# define MAP_ERRORS_H

# include "ft_printf.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct map_errors
{
	bool		has_minimum_dimensions;
	bool		has_invalid_chars;
	bool		has_holes;
	bool		is_a_rectangle;
	bool		has_valid_cpe_amount;
	bool		has_valid_path;
	int			count;
}				t_map_errors;

t_map_errors	*init_map_errors(void);
int				count_errors(t_map_errors *map_errors);
void			print_map_errors(t_map_errors *map_errors);

# define ERR_HOLES "The map must be closed/surrounded by walls"
# define ERR_INVALID_CHARS "Valid map characters: 0, 1, C, E, P"
# define ERR_MAP_SIZE "The map is too small"
# define ERR_CPE_AMOUNT "The map must contain 1 E, at least 1 C, and 1 P"
# define ERR_MAP_SHAPE "The map must be rectangular"
# define ERR_INVALID_PATH "There is NO valid path in the map"

#endif