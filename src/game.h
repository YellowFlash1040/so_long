#ifndef GAME_H
# define GAME_H

// # include "mlx.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>

# define TITLE "so_long"

typedef void	*t_client;
typedef void	*t_window;
typedef void	*t_image;

typedef struct data
{
	t_client	display;
	t_window	window;
}				t_data;

#endif