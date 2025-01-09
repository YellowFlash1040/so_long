/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:58:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 14:58:35 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->rows = NULL;
	map->rows_count = -1;
	map->columns_count = -1;
	map->collectibles_count = -1;
	return (map);
}

void	free_map(t_map **map_address)
{
	t_map	*map;
	int		i;

	map = *map_address;
	if (map)
	{
		if (map->rows)
		{
			i = -1;
			while (map->rows[++i])
				free(map->rows[i]);
			free(map->rows);
		}
		free(map);
		*map_address = NULL;
	}
}
