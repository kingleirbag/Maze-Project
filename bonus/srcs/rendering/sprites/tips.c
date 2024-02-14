#include "maze.h"

void	show_door_tip(t_game *g, int z)
{
	static int	frames = 0;

	if (g->objects[z].visible)
	{
		if (frames > 10)
		{
			g->tips.open_door = !g->tips.open_door;
			frames = 0;
		}
		frames++;
	}
	else
	{
		g->tips.open_door = false;
		frames = 0;
	}
}

void	show_game_over_tip(t_game *g)
{
	static int	frames = 0;

	if (frames > 10)
	{
		g->tips.game_over = !g->tips.game_over;
		frames = 0;
	}
	frames++;
}
