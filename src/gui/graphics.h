/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:22:30 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/19 18:17:39 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "converter.h"
# include "data.h"
# include "ft_printf.h"
# include "ft_string.h"

void	draw_map(t_data *data);
void	print_movements_count(t_data *data);
void	update_graphic_player_position(t_data *data);

#endif