/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:09:01 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/19 17:51:50 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "mlx.h"
# include <stdbool.h>
# include <stdlib.h>

typedef void			*t_image;

typedef char			t_pixel_byte;
typedef unsigned int	t_pixel;

typedef struct image_data
{
	t_pixel_byte		*pixels;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_image_data;

t_image_data			*init_image_data(void);
t_image_data			*get_image_data(t_image *image);
t_pixel					*get_pixel(t_image_data *img_data, int x, int y);
bool					is_transparent(t_pixel *pixel);

#endif