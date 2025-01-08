/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:31:39 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/08 14:19:46 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	so_long(void)
{
	t_data	data;

	data.display = mlx_init();
	if (!data.display)
		return (1);
	data.window = mlx_new_window(data.display, 1000, 1000, TITLE);
	if (!data.window)
	{
		mlx_destroy_display(data.display);
		free(data.display);
		return (1);
	}
	mlx_hook(data.window, KeyPress, KeyPressMask, handle_key_pressed, &data);
	mlx_loop(data.display);
	return (0);
}
