/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/18 17:07:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

static bool	has_valid_extension(char *filepath);
static void	free_lines(char ***lines_address);

int	parse_map(char *filepath, t_map **map_adr)
{
	char	**lines;
	int		lines_count;
	t_map	*map;
	int		i;

	*map_adr = NULL;
	if (!has_valid_extension(filepath))
		return (print_failure(MAP_EXTENSION_ERR_MSG), MAP_EXTENSION_ERR);
	lines = read_all_lines(filepath, &lines_count);
	if (!lines)
		return (EMPTY_FILE_ERR);
	map = init_map();
	if (!map)
		return (free_lines(&lines), MAP_INIT_ERROR);
	i = -1;
	while (++i < lines_count)
		replace(lines[i], '\n', '\0');
	map->rows = lines;
	map->rows_count = lines_count;
	map->columns_count = ft_strlen(map->rows[0]);
	*map_adr = map;
	return (0);
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
	return (false);
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
