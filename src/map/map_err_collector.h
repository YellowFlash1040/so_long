/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_collector.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:26:46 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/12 12:36:17 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERR_COLLECTOR_H
# define MAP_ERR_COLLECTOR_H

# include "map_data.h"
# include "map_errors.h"

t_map_errors	*collect_map_errors(t_map_data *map_data);

#endif