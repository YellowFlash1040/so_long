/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/11 16:24:55 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"
#include "map_validator.h"
#include "path_checker.h"

void			print_map(t_map *map);
void			print_success(char *str);
void			print_failure(char *str);
int				find_collectibles_count(t_map *map);
t_coordinates	find_player_position(t_map *map);

int	main(void)
{
	t_map			*map;
	int				result;
	t_coordinates	player_position;

	map = parse_map("maps/path_check/map5.ber");
	map->collectibles_count = find_collectibles_count(map);
	player_position = find_player_position(map);
	result = has_valid_path(map, player_position);
	free_map(&map);
	if (result == -1)
		print_failure("Something went wrong");
	else if (result == 1)
		print_success("There is a valid path");
	else
		print_failure("There is NO valid path");
	return (0);
}

void	print_success(char *str)
{
	ft_printf("\033[0;32m%s ✅\n\033[0m", str);
}

void	print_failure(char *str)
{
	ft_printf("\033[31mError\n%s ❌\n\033[0m", str);
}

int	find_collectibles_count(t_map *map)
{
	int	collectibles_count;
	int	x;
	int	y;

	collectibles_count = 0;
	y = -1;
	while (++y < map->rows_count)
	{
		x = -1;
		while (++x < map->columns_count)
			if (map->rows[y][x] == 'C')
				collectibles_count++;
	}
	return (collectibles_count);
}

t_coordinates	find_player_position(t_map *map)
{
	t_coordinates	player_position;
	int				x;
	int				y;

	player_position.x = -1;
	player_position.y = -1;
	y = -1;
	while (++y < map->rows_count)
	{
		x = index_of('P', map->rows[y]);
		if (x != -1)
		{
			player_position.x = x;
			player_position.y = y;
			return (player_position);
		}
	}
	return (player_position);
}
