#include "path_checker.h"

t_maze_data	merge_data(t_maze_data current, t_maze_data new_data)
{
	current.collectibles_count += new_data.collectibles_count;
	current.is_exit_reachable |= new_data.is_exit_reachable;
	return (current);
}

bool	neighbor_is_an_exit(t_cell *cells, t_neighbors neighbors)
{
	if (cells[neighbors.top].value == 'E')
		return (true);
	if (cells[neighbors.right].value == 'E')
		return (true);
	if (cells[neighbors.bottom].value == 'E')
		return (true);
	if (cells[neighbors.left].value == 'E')
		return (true);
	return (false);
}
