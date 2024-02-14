#include "maze.h"

void	cub_pixel_put(t_game *g, float x, float y, int color)
{
	t_image	*image;
	char	*dst;
	int		int_x;
	int		int_y;

	image = &g->frame;
	int_x = (int)round(x);
	int_y = (int)round(y);
	if (x < 0 || x > g->win.width || y < 0 || y > g->win.height)
		return ;
	dst = image->addr + (int_y * image->line_length
			+ int_x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}
