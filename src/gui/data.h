/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:55:45 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/15 13:30:38 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "assets.h"
# include "client.h"
# include "game_data.h"

typedef struct data
{
	t_client	*user;
	t_assets	*assets;
	t_game_data	*game;
}				t_data;

void			free_data(t_data *data);

#endif