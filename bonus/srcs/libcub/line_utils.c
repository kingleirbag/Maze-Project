#include "maze.h"

bool line_empty(char *line)
{
	int i;

	i = -1;
	while (line[++i] == 32 || (line[i] >= 9 && line[i] <= 13))
		;
	return (line[i] == '\0' || line[i] == '\n');
}
