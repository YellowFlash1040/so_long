/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_toolkit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 14:03:49 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 14:10:51 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_TOOLKIT_H
# define MAP_TOOLKIT_H

# include "map_analyzer.h"
# include "map_err_collector.h"
# include "map_parser.h"
# include "path_checker.h"
# include <stdio.h>

# define MAP_INIT_ERROR 1
# define MAP_DATA_INIT_ERROR 2
# define MAP_ERRORS_INIT_ERROR 3

int	process_map(char *filepath);

#endif
