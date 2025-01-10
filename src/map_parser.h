/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:00:27 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 13:44:12 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# define MAP_EXTENSION ".ber"

# define MAP_EXTENSION_ERROR "The map file must have a .ber extension. ❌"

# include "file.h"
# include "ft_printf.h"
# include "map.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_map	*parse_map(char *filepath);

#endif