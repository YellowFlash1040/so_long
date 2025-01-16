/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:54:17 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 17:04:33 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_H
# define ASSETS_H

# include "client.h"
# include "ft_string.h"
# include "image.h"
# include "mlx.h"
# include "sprite.h"
# include <stdlib.h>

typedef struct assets
{
	t_image	wall;
	t_image	ground;
	t_image	player;
	t_image	exit;
	t_image	collectible;
}			t_assets;

t_assets	*load_assets(t_display *display);
void		free_assets(t_display *display, t_assets *assets);

#endif