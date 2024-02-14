#include "maze.h"

int	cub_file_open(t_game *g, int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		if (errno == EACCES)
			return (cub_errors_setter(g, FILE_PERMISSION_DENIED));
		else if (errno == ENOENT)
			return (cub_errors_setter(g, FILE_NOT_FOUND));
		else
			return (cub_errors_setter(g, FILE_UNKNOWN_ERROR));
	}
	return (RETURN_SUCCESS);
}
