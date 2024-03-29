#include "maze.h"

int	cub_free_double_ptr(void **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		cub_free(tab[i]);
	cub_free(tab);
	return (RETURN_DEFAULT);
}

int	cub_free_double_int(int **tab, size_t size)
{
	int	i;

	i = -1;
	while ((size_t)++i < size)
		cub_free(tab[i]);
	cub_free(tab);
	return (RETURN_DEFAULT);
}

int	cub_free(void *ptr)
{
	free(ptr);
	return (RETURN_DEFAULT);
}

int	cub_free_memory(t_game *g)
{
	if (g->allocated.map)
		cub_free_double_int(g->map.arr, g->win.height);
	exit(EXIT_SUCCESS);
}
