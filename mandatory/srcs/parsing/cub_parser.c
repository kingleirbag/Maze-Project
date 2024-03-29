#include "maze.h"

void	cub_init_game_struct(t_game *g, char *filename)
{
	g->win.width = WIN_WIDTH;
	g->win.height = WIN_HEIGHT;
	g->map.file.path = filename;
	g->parsing.is_map = false;
	g->parsing.map_initialized = false;
	g->parsing.has_north = false;
	g->parsing.has_south = false;
	g->parsing.has_west = false;
	g->parsing.has_east = false;
	g->parsing.has_floor = false;
	g->parsing.has_ceiling = false;
	g->paused = false;
	g->freeze = false;
	g->game_over = false;
	g->rays = (t_ray *) malloc(NUM_RAYS * sizeof(t_ray));
	if (!g->rays)
		cub_errors_exit(g, "Failed to allocate memory for rays");
}

int	cub_parser(t_game *g, char *filename)
{
	cub_init_game_struct(g, filename);
	if (cub_file_parser(g))
		return (RETURN_FAILURE);
	if (close(g->map.file.fd) == -1)
		return (cub_errors_setter(g, "Failed to close config file"));
	if (cub_check_map(g))
		return (RETURN_FAILURE);
	if (cub_check_occurences(g))
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}
