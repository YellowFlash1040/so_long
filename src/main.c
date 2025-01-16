/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 18:17:52 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "map_toolkit.h"

void	print_usage_message(void);

int	main(int argsc, char **args)
{
	char	*filepath;
	t_map	*map;
	char	processing_result;

	if (argsc != 2)
	{
		print_usage_message();
		return (1);
	}
	filepath = args[1];
	processing_result = process_map_file(filepath, &map);
	if (processing_result != 0)
		return (processing_result);
	start_game(map);
	return (0);
}

void	print_usage_message(void)
{
	ft_printf("\033[31mError\n\033[0m");
	ft_printf("\033[1;33mUsage: [binary_name] [map_file_path].ber\n\033[0m");
}
