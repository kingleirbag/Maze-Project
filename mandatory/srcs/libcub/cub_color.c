#include "maze.h"

int	create_rgb(t_color color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}
