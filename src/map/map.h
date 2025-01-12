/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:08:56 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 12:41:29 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

typedef struct map
{
	char	**rows;
	int		rows_count;
	int		columns_count;
	int		collectibles_count;
}			t_map;

typedef struct coordinates
{
	int		x;
	int		y;
}			t_coordinates;

t_map		*init_map(void);
void		free_map(t_map **map);

#endif