#include "maze.h"

int	cub_check_disponibility(t_game *g)
{
	return (cub_file_open(g, &g->map.file.fd, g->map.file.path));
}

int	cub_check_extension(t_game *g)
{
	char	**ext;
	int		i;

	i = cub_count_occurences(g->map.file.path, '.');
	if (!i)
		return (cub_errors_setter(g, EXTENSION_NO_OCCUR));
	if (i > 1 && !(i == 2 && g->map.file.path[0] == '.'))
		return (cub_errors_setter(g, EXTENSION_MULTIPLE));
	ext = ft_split(g->map.file.path, ".");
	if (!ext)
		return (cub_errors_setter(g, ERR_MALLOC));
	i = -1;
	while (ext[++i])
		;
	if (ft_strncmp(ext[i - 1], "cub", 4))
		return (cub_free_double_ptr((void **) ext)
			+ cub_errors_setter(g, EXTENSION_INVALID));
	cub_free_double_ptr((void **) ext);
	return (RETURN_SUCCESS);
}
