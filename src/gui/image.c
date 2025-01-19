/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:52:43 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/19 17:49:01 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_image_data	*init_image_data(void)
{
	t_image_data	*image_data;

	image_data = (t_image_data *)malloc(sizeof(image_data));
	if (!image_data)
		return (NULL);
	image_data->pixels = NULL;
	image_data->bits_per_pixel = 0;
	image_data->line_length = 0;
	image_data->endian = 0;
	return (image_data);
}

t_image_data	*get_image_data(t_image *image)
{
	t_image_data	*img_data;

	img_data = init_image_data();
	if (!img_data)
		return (NULL);
	img_data->pixels = mlx_get_data_addr(image, &img_data->bits_per_pixel,
			&img_data->line_length, &img_data->endian);
	if (!img_data->pixels)
		return (free(img_data), NULL);
	return (img_data);
}

t_pixel	*get_pixel(t_image_data *img_data, int x, int y)
{
	t_pixel	*pixel;
	int		offset;

	offset = y * img_data->line_length + x * (img_data->bits_per_pixel / 8);
	pixel = (t_pixel *)(img_data->pixels + offset);
	return (pixel);
}

bool	is_transparent(t_pixel *pixel)
{
	int	alpha;

	alpha = (*pixel >> 24) & 0xFF;
	if (alpha == 255)
		return (true);
	return (false);
}
