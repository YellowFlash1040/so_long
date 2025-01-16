/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:00:34 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:19:43 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
# define MOVEMENTS_H

# include "direction.h"
# include "game_data.h"
# include <X11/keysym.h>
# include <stdbool.h>

# define STEP 64

// # define KEY_UP XK_a
// # define KEY_DOWN XK_d
// # define KEY_LEFT XK_w
// # define KEY_RIGHT XK_s

# define KEY_UP XK_Up
# define KEY_DOWN XK_Down
# define KEY_LEFT XK_Left
# define KEY_RIGHT XK_Right

bool	can_player_go(t_direction direction, t_game_data *game_data);
void	player_go(t_direction direction, t_game_data *game_data);
bool	is_player_position_changed(t_game_data *game_data);
bool	is_movement_key(int keysym);

#endif