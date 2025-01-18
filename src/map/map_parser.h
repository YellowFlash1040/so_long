/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:00:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/18 17:01:07 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "file.h"
# include "map.h"
# include "printer.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAP_EXTENSION ".ber"

# define MAP_EXTENSION_ERR 10
# define EMPTY_FILE_ERR 11
# define MAP_INIT_ERROR 12

# define MAP_EXTENSION_ERR_MSG "The map file must have a .ber extension"
# define EMPTY_FILE_ERR_MSG "The map file is empty"

int	parse_map(char *filepath, t_map **map_adr);

#endif