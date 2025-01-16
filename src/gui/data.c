/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:30:47 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/15 13:42:45 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"

void	free_data(t_data *data)
{
	if (data)
	{
		if (data->game)
			free_game_data(data->game);
		if (data->assets)
			free_assets(data->user->display, data->assets);
		if (data->user)
			destroy_window(data->user);
		free(data);
	}
}
