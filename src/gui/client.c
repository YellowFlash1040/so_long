/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:31:50 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 16:32:23 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	*create_window(int width, int height, char *title)
{
	t_client	*user;

	user = (t_client *)malloc(sizeof(t_client));
	if (!user)
		return (NULL);
	user->display = mlx_init();
	user->window = mlx_new_window(user->display, width, height, title);
	user->dimensions = (t_dimensions){.width = width, .height = height};
	return (user);
}

void	destroy_window(t_client *client)
{
	mlx_destroy_window(client->display, client->window);
	mlx_destroy_display(client->display);
	free(client->display);
	free(client);
}
