#include "maze.h"

int file_open(t_game *g, int *fd, char *filename)
{
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		if (errno == EACCES)
			return (errors_setter(g, FILE_PERMISSION_DENIED));
		else if (errno == ENOENT)
			return (errors_setter(g, FILE_NOT_FOUND));
		else
			return (errors_setter(g, FILE_UNKNOWN_ERROR));
	}
	return (RETURN_SUCCESS);
}
