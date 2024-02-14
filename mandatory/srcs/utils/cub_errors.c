#include "maze.h"

void	cub_errors_exit(t_game *g, char *err)
{
	ft_putstr_fd(ERROR "Error\n" RESET, STDERR_FILENO);
	ft_putstr_fd(err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	if (g->allocated.map)
		cub_free_double_int(g->map.arr, (size_t) g->win.height);
	exit(EXIT_FAILURE);
}

int	cub_errors_setter(t_game *g, char *err)
{
	g->error.message = err;
	g->error.code = 1;
	return (RETURN_DEFAULT);
}

int	cub_errors_map(t_game *g, size_t size, char *err)
{
	return (cub_free_double_int(g->map.arr, size)
		+ cub_errors_setter(g, err));
}
