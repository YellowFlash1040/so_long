/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:59:32 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:34:09 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "dimension.h"
# include "mlx.h"
# include <stdlib.h>

typedef void		*t_display;
typedef void		*t_window;

typedef struct client
{
	t_display		display;
	t_window		window;
	t_dimensions	dimensions;
}					t_client;

t_client			*create_window(int width, int height, char *title);
void				destroy_window(t_client *client);

#endif