/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:54:20 by akovtune          #+#    #+#             */
/*   Updated: 2025/01/16 17:08:58 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assets.h"

static char	**get_file_paths(void);
void		free_filepaths(char **filepaths);

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
	assets->player = mlx_xpm_file_to_image(display, filepaths[4], &(int){0},
			&(int){0});
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

void	free_filepaths(char **filepaths)
{
	int	i;

	i = -1;
	while (filepaths[++i])
		free(filepaths[i]);
	free(filepaths);
}
