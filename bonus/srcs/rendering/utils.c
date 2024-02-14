#include "maze.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_image	get_texture(t_game *g, int ind)
{
	if (g->rays[ind].content_hit >= 1 && g->rays[ind].content_hit <= 5)
		return (g->textures.walls[g->rays[ind].content_hit - 1]);
	return (g->textures.walls[0]);
}
