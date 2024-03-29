#include "maze.h"

static bool	is_invalid_border(int c)
{
	if (c == 0 || c == PLAYER)
		return (true);
	return (false);
}

static int	cub_check_map_components(t_game *g, int i, int j)
{
	if (j + 1 < g->map.width && g->map.arr[i][j] == -1
		&& is_invalid_border(g->map.arr[i][j + 1]))
		return (cub_errors_setter(g, MAP_INVALID_BORDER));
	if (i + 1 < g->map.height && g->map.arr[i][j] == -1
		&& is_invalid_border(g->map.arr[i + 1][j]))
		return (cub_errors_setter(g, MAP_INVALID_BORDER));
	if (j + 1 < g->map.width && is_invalid_border(g->map.arr[i][j])
		&& g->map.arr[i][j + 1] == -1)
		return (cub_errors_setter(g, MAP_INVALID_BORDER));
	if (i + 1 < g->map.height && is_invalid_border(g->map.arr[i][j])
		&& g->map.arr[i + 1][j] == -1)
		return (cub_errors_setter(g, MAP_INVALID_BORDER));
	return (RETURN_SUCCESS);
}

int	cub_check_map(t_game *g)
{
	t_iterators	it;

	it.i = -1;
	while (++it.i < g->map.width)
		if (is_invalid_border(g->map.arr[0][it.i])
			|| is_invalid_border(g->map.arr[g->map.height - 1][it.i]))
			return (cub_errors_setter(g, MAP_INVALID_BORDER));
	it.i = -1;
	while (++it.i < g->map.height)
		if (is_invalid_border(g->map.arr[it.i][0])
			|| is_invalid_border(g->map.arr[it.i][g->map.width - 1]))
			return (cub_errors_setter(g, MAP_INVALID_BORDER));
	it.i = -1;
	while (++it.i < g->map.height)
	{
		it.j = -1;
		while (++it.j < g->map.width)
			if (cub_check_map_components(g, it.i, it.j))
				return (RETURN_FAILURE);
	}
	return (RETURN_SUCCESS);
}

int	cub_check_occurences(t_game *g)
{
	int	i;
	int	occur;

	occur = 0;
	i = -1;
	while (++i < g->map.height)
		occur += cub_count_int_occurences(g->map.arr[i], g->map.width, PLAYER);
	if (!occur)
		return (cub_errors_setter(g, MAP_NO_PLAYERS));
	else if (occur > 1)
		return (cub_errors_setter(g, MAP_MULTIPLE_PLAYERS));
	return (RETURN_SUCCESS);
}

int	cub_map_check(t_game *g, char *line)
{
	static unsigned int	lines_before_map = 0;

	if (g->parsing.has_north && g->parsing.has_south && g->parsing.has_west
		&& g->parsing.has_east && g->parsing.has_floor && g->parsing.has_ceiling
		&& !cub_line_empty(line) && !g->parsing.is_map)
	{
		g->parsing.is_map = true;
		g->parsing.lines_before_map = lines_before_map;
	}
	if (!g->parsing.is_map)
		lines_before_map++;
	return (RETURN_SUCCESS);
}
