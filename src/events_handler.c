#include "events_handler.h"

int	handle_key_pressed(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->display, data->window);
		mlx_destroy_display(data->display);
		free(data->display);
		exit(0);
	}
	return (0);
}
