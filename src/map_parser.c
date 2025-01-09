/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/09 12:59:14 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

static bool	has_valid_extension(char *filepath);
static void	free_lines(char ***lines_address);

t_map	*parse_map(char *filepath)
{
	char	**lines;
	int		lines_count;
	t_map	*map;

	if (!has_valid_extension(filepath))
		return (NULL);
	lines = read_all_lines(filepath, &lines_count);
	if (!lines)
		return (NULL);
	map = init_map();
	if (!map)
		return (free_lines(&lines), NULL);
	map->rows = lines;
	map->rows_count = lines_count;
	return (map);
}

static bool	has_valid_extension(char *filepath)
{
	char	*extension;
	bool	is_valid;

	extension = get_file_extension(filepath);
	is_valid = ft_strcmp(extension, ".ber");
	free(extension);
	if (is_valid)
		return (true);
	ft_printf("\033[31mError\n");
	ft_printf("The map file must have a .ber extension.\033[0m\n");
	return (NULL);
}

static void	free_lines(char ***lines_address)
{
	int		i;
	char	**lines;

	lines = *lines_address;
	if (lines)
	{
		i = -1;
		while (lines[++i])
			free(lines[i]);
		free(lines);
		*lines_address = NULL;
	}
}
