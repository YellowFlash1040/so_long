/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 13:44:49 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map_validator.h"

bool	check_map(char *filepath);
void	print_map(t_map *map);

int	main(void)
{
	int		maps_amount;
	char	*maps[] = {"maps/map1.ber", "maps/map2.ber", "maps/map3.ber",
			"maps/map4.ber", "maps/map5.ber", "maps/map6.ber", "maps/map7.ber",
			"maps/map8.ber", "maps/map9.ber", "maps/map10.ber",
			"maps/map11.ber", "maps/map12.ber", "Makefile", "mlx.tgz",
			"src/main.c"};

	maps_amount = sizeof(maps) / sizeof(char *);
	for (int i = 0; i < maps_amount; i++)
	{
		if (ft_strcmp(maps[i], "maps/map9.ber"))
			check_map(maps[i]);
		else
			check_map(maps[i]);
		ft_printf("\n");
	}
	return (0);
}

bool	check_map(char *filepath)
{
	t_map	*map;
	int		is_valid;

	map = parse_map(filepath);
	if (!map)
		return (1);
	print_map(map);
	is_valid = is_valid_map(map);
	free_map(&map);
	if (is_valid == false)
	{
		ft_printf("\033[31mError\nThe map is invalid ❌\n\033[0m");
		return (1);
	}
	else if (is_valid == -1)
	{
		ft_printf("Malloc failed\n");
		return (1);
	}
	ft_printf("\033[0;32mMap is valid ✅\n\033[0m");
	return (0);
}

void	print_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows_count)
		ft_printf("%s\n", map->rows[i]);
}
