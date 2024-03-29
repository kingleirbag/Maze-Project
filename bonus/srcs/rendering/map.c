#include "maze.h"

typedef struct s_draw_map
{
	float		center_x;
	float		center_y;
	float		radius_x;
	float		radius_y;
	float		world_x;
	float		world_y;
	int			factor;
	bool		top;
	bool		bottom;
	bool		left;
	bool		right;
	t_iterators	it;
}	t_draw_map;

static void	put_color(t_game *g, t_draw_map *s, int color)
{
	pixel_put(g, s->center_x + s->it.j - s->radius_x,
		s->center_y + s->it.i - s->radius_y, color);
}

static void	minimap_check_walls(t_game *g, t_draw_map *s)
{
	s->top = ((!has_wall_at(g, s->world_x, s->world_y - s->factor)
				|| has_door_at(g, s->world_x, s->world_y - s->factor))
			&& !has_void_at(g, s->world_x, s->world_y - s->factor));
	s->bottom = ((!has_wall_at(g, s->world_x, s->world_y + s->factor)
				|| has_door_at(g, s->world_x, s->world_y + s->factor))
			&& !has_void_at(g, s->world_x, s->world_y + s->factor));
	s->left = ((!has_wall_at(g, s->world_x - s->factor, s->world_y)
				|| has_door_at(g, s->world_x - s->factor, s->world_y))
			&& !has_void_at(g, s->world_x - s->factor, s->world_y));
	s->right = ((!has_wall_at(g, s->world_x + s->factor, s->world_y)
				|| has_door_at(g, s->world_x + s->factor, s->world_y))
			&& !has_void_at(g, s->world_x + s->factor, s->world_y));
}

static bool	is_door_closed(t_game *g, t_draw_map *s)
{
	int		x;
	int		y;

	x = (int)(s->world_x / TILE_SIZE);
	y = (int)(s->world_y / TILE_SIZE);
	return (g->map.arr[y][x] == DOOR_CLOSED);
}

static void	draw_x_radius(t_game *g, t_draw_map *s)
{
	while (++s->it.j <= s->radius_x * 2)
	{
		if (s->it.i == 0 || s->it.j == 0
			|| s->it.i == s->radius_y * 2 || s->it.j == s->radius_x * 2)
			put_color(g, s, 0xFFFFFF);
		else
		{
			s->world_x = g->player.pos.x + s->factor * (s->it.j - s->radius_x);
			s->world_y = g->player.pos.y + s->factor * (s->it.i - s->radius_y);
			if (has_void_at(g, s->world_x, s->world_y))
				put_color(g, s, 0x000000);
			else if (is_door_closed(g, s))
				put_color(g, s, 0x003300);
			else if (has_wall_at(g, s->world_x, s->world_y))
			{
				minimap_check_walls(g, s);
				if (s->top || s->bottom || s->left || s->right)
					put_color(g, s, 0xFFFFFF);
				else
					put_color(g, s, 0x000000);
			}
		}
	}
}

void	draw_map(t_game *g)
{
	t_draw_map	s;

	s.center_x = WIN_WIDTH / 2;
	s.center_y = WIN_HEIGHT / 2;
	s.radius_x = WIN_WIDTH * 0.3;
	s.radius_y = WIN_HEIGHT * 0.3;
	s.factor = 2;
	s.it.i = -1;
	while (++s.it.i <= s.radius_y * 2)
	{
		s.it.j = -1;
		draw_x_radius(g, &s);
	}
	s.it.i = -1;
	while (++s.it.i < PLAYER_MINIMAP_HEIGHT * 2)
	{
		s.it.j = -1;
		while (++s.it.j < PLAYER_MINIMAP_WIDTH * 2)
			pixel_put(g, s.center_x + s.it.j - PLAYER_MINIMAP_WIDTH,
				s.center_y + s.it.i - PLAYER_MINIMAP_HEIGHT, 0xFF0000);
	}
}
