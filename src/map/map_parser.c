/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 15:58:06 by akovtune         ###   ########.fr       */
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
	int		i;

	if (!has_valid_extension(filepath))
		return (NULL);
	lines = read_all_lines(filepath, &lines_count);
	if (!lines)
		return (NULL);
	map = init_map();
	if (!map)
		return (free_lines(&lines), NULL);
	i = -1;
	while (++i < lines_count)
		replace(lines[i], '\n', '\0');
	map->rows = lines;
	map->rows_count = lines_count;
	map->columns_count = ft_strlen(map->rows[0]);
	return (map);
}

static bool	has_valid_extension(char *filepath)
{
	char	*extension;
	bool	is_valid;

	extension = get_file_extension(filepath);
	is_valid = ft_strcmp(extension, MAP_EXTENSION);
	free(extension);
	if (is_valid)
		return (true);
	ft_printf("\033[31mError\n");
	ft_printf("%s\033[0m\n", MAP_EXTENSION_ERROR);
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
