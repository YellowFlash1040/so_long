/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:30:09 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/14 15:17:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_errors.h"

t_map_errors	*init_map_errors(void)
{
	t_map_errors	*map_errors;

	map_errors = (t_map_errors *)malloc(sizeof(t_map_errors));
	if (!map_errors)
		return (NULL);
	map_errors->count = 0;
	map_errors->has_holes = false;
	map_errors->has_invalid_chars = false;
	map_errors->has_minimum_dimensions = true;
	map_errors->has_valid_cpe_amount = true;
	map_errors->has_valid_path = true;
	map_errors->is_a_rectangle = true;
	return (map_errors);
}

int	count_errors(t_map_errors *map_errors)
{
	int	count;

	count = 0;
	if (map_errors->has_holes)
		count++;
	if (map_errors->has_invalid_chars)
		count++;
	if (!map_errors->has_minimum_dimensions)
		count++;
	if (!map_errors->has_valid_cpe_amount)
		count++;
	if (!map_errors->is_a_rectangle)
		count++;
	return (count);
}

void	print_map_errors(t_map_errors *map_errors)
{
	ft_printf("\033[31mError\n");
	if (map_errors->has_holes)
		ft_printf("%s ❌\n", ERR_HOLES);
	if (map_errors->has_invalid_chars)
		ft_printf("%s ❌\n", ERR_INVALID_CHARS);
	if (!map_errors->has_minimum_dimensions)
		ft_printf("%s ❌\n", ERR_MAP_SIZE);
	if (!map_errors->has_valid_cpe_amount)
		ft_printf("%s ❌\n", ERR_CPE_AMOUNT);
	if (!map_errors->is_a_rectangle)
		ft_printf("%s ❌\n", ERR_MAP_SHAPE);
	if (!map_errors->has_valid_path)
		ft_printf("%s ❌\n", ERR_INVALID_PATH);
	ft_printf("\033[0m");
}
