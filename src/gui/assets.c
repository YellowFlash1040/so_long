/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:54:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/19 17:58:34 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static char	**get_file_paths(void);
static void	free_filepaths(char **filepaths);
static int	combine_images(t_image img1, t_image img2);

t_assets	*load_assets(t_display *display)
{
	t_assets	*assets;
	char		**filepaths;

	assets = (t_assets *)malloc(sizeof(t_assets));
	if (!assets)
		return (NULL);
	filepaths = get_file_paths();
	if (!filepaths)
		return (NULL);
	assets->ground = mlx_xpm_file_to_image(display, filepaths[0], &(int){0},
			&(int){0});
	assets->wall = mlx_xpm_file_to_image(display, filepaths[1], &(int){0},
			&(int){0});
	assets->exit = mlx_xpm_file_to_image(display, filepaths[2], &(int){0},
			&(int){0});
	assets->collectible = mlx_xpm_file_to_image(display, filepaths[3],
			&(int){0}, &(int){0});
	combine_images(assets->collectible, assets->ground);
	assets->player = mlx_xpm_file_to_image(display, filepaths[4], &(int){0},
			&(int){0});
	combine_images(assets->player, assets->ground);
	free_filepaths(filepaths);
	return (assets);
}

static char	**get_file_paths(void)
{
	char	**filepaths;
	char	*assets_folder;
	int		assets_count;

	assets_folder = "./assets/";
	assets_count = 5;
	filepaths = (char **)malloc(sizeof(char *) * (assets_count + 1));
	if (!filepaths)
		return (NULL);
	filepaths[0] = ft_strjoin(assets_folder, "ground.xpm");
	filepaths[1] = ft_strjoin(assets_folder, "wall.xpm");
	filepaths[2] = ft_strjoin(assets_folder, "exit.xpm");
	filepaths[3] = ft_strjoin(assets_folder, "collectible.xpm");
	filepaths[4] = ft_strjoin(assets_folder, "player.xpm");
	filepaths[5] = NULL;
	return (filepaths);
}

void	free_assets(t_display *display, t_assets *assets)
{
	mlx_destroy_image(display, assets->wall);
	mlx_destroy_image(display, assets->ground);
	mlx_destroy_image(display, assets->player);
	mlx_destroy_image(display, assets->exit);
	mlx_destroy_image(display, assets->collectible);
	free(assets);
}

static void	free_filepaths(char **filepaths)
{
	int	i;

	i = -1;
	while (filepaths[++i])
		free(filepaths[i]);
	free(filepaths);
}

static int	combine_images(t_image img1, t_image img2)
{
	t_image_data	*img1_data;
	t_image_data	*img2_data;
	t_point			position;
	t_pixel			*pixel1;
	t_pixel			*pixel2;

	img1_data = get_image_data(img1);
	if (!img1_data)
		return (1);
	img2_data = get_image_data(img2);
	if (!img2_data)
		return (free(img1_data), 1);
	position.y = -1;
	while (++position.y < SPRITE_HEIGHT)
	{
		position.x = -1;
		while (++position.x < SPRITE_WIDTH)
		{
			pixel1 = get_pixel(img1_data, position.x, position.y);
			pixel2 = get_pixel(img2_data, position.x, position.y);
			if (is_transparent(pixel1))
				*pixel1 = *pixel2;
		}
	}
	return (free(img1_data), free(img2_data), 0);
}
