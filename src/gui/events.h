/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:54:14 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 15:16:47 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "data.h"
# include "ft_printf.h"
# include "graphics.h"
# include "movements.h"
# include <X11/X.h>

# define FRAME_DELAY 500000
# define FRAME_COUNT 8

void	subscribe_to_events(t_client *user, t_data *data);
void	listen_for_events(t_client *user);

#endif