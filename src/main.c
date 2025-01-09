/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 14:22:24 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	main(void)
{
	t_map	*map;

	map = parse_map("map.ber");
	if (!map)
		return (1);
	ft_printf("rows: %d\n", map->rows_count);
	ft_printf("columns: %d\n", map->columns_count);
	ft_printf("collectibles: %d\n", map->collectibles_count);
	free_map(&map);
	return (0);
}
