/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/10 18:26:48 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

# include "ft_string.h"
# include "map_data.h"
# include <stdbool.h>
# include <stdlib.h>

int	is_valid_map(t_map *map);

#endif