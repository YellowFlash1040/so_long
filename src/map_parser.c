/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:29 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 14:12:41 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

void	free_lines(char **lines);

bool	parse_map(char *filePath)
{
	char	*extension;
	char	**lines;
	int		i;
	int		first_line_length;

	extension = get_file_extension(filePath);
	if (!ft_strcmp(extension, ".ber"))
	{
		printf("\033[31mError: The map file must have a .ber extension.\033[0m\n");
		return (free(extension), false);
	}
	free(extension);
	lines = read_all_lines(filePath);
	if (!lines)
	{
		printf("first line length = %p\n", lines);
		return (1);
	}
	i = 0;
	first_line_length = ft_strlen(lines[i]);
	if (first_line_length == 0)
	{
		printf("\033[31mError: The map file is empty.\033[0m\n");
		return (free_lines(lines), false);
	}
	while (lines[++i])
	{
		printf("line length = %d\n", ft_strlen(lines[i]));
		if (ft_strlen(lines[i]) != first_line_length)
		{
			printf("\033[31mError: Invalid map file. The map must be a rectangle.\033[0m\n");
			return (free_lines(lines), false);
		}
	}
	free_lines(lines);
	return (true);
}

void	free_lines(char **lines)
{
	int	i;

	i = -1;
	while (lines[++i])
		free(lines[i]);
	free(lines);
}
