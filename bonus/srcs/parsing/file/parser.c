#include "maze.h"

int	file_parser(t_game *g)
{
	if (check_disponibility(g))
		return (RETURN_FAILURE);
	if (check_extension(g))
		return (RETURN_FAILURE);
	if (parse_config(g))
		return (RETURN_FAILURE);
	return (RETURN_SUCCESS);
}

int	parse_config(t_game *g)
{
	char	*line;

	while (true)
	{
		line = get_next_line(g->map.file.fd);
		if (!line)
			break ;
		if (line_empty(line))
		{
			if (g->parsing.map_initialized)
				return (free_ptr(line), errors_setter(g, MAP_EMPTY_LINE));
			map_check(g, line);
			free_ptr(line);
			continue ;
		}
		map_check(g, line);
		if (g->parsing.is_map)
			if (map_parse(g, line))
				return (free_ptr(line), RETURN_FAILURE);
		free_ptr(line);
	}
	return (RETURN_SUCCESS);
}
