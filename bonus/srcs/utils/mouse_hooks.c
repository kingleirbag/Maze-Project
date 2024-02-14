#include "maze.h"

int	hook_mouse_press(int code, int x, int y, t_game *g)
{
	(void) x, (void) y;
	if (code == 1)
		g->mouse.left = true;
	else if (code == 2)
		g->mouse.right = true;
	return (RETURN_SUCCESS);
}

int	hook_mouse_release(int code, int x, int y, t_game *g)
{
	(void) x, (void) y;
	if (code == 1 && !g->player.shooting && !g->display_map && !g->paused)
	{
		g->player.shooting = true;
		g->mouse.left = false;
	}
	else if (code == 2 && !g->player.shooting && !g->display_map && !g->paused)
		g->mouse.right = false;
	return (RETURN_SUCCESS);
}
