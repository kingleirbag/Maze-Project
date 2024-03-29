#include "maze.h"

void	display_medkit_splash(t_game *g)
{
	static int	frames = 0;

	if (frames > 5)
	{
		g->player.taking_medkit = false;
		frames = 0;
	}
	frames++;
}

bool	check_for_medkits(t_game *g, int z)
{
	float	distance;

	if (g->objects[z].display)
	{
		distance = hypot(g->player.pos.x - g->objects[z].pos.x,
				g->player.pos.y - g->objects[z].pos.y);
		if (distance < 50.0f && g->player.health < 100)
		{
			g->player.taking_medkit = true;
			g->player.health += MEDKIT_HEALING;
			g->objects[z].display = false;
			return (false);
		}
		return (true);
	}
	return (false);
}
