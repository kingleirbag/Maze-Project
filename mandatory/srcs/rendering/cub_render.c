#include "maze.h"

void	raycast(t_game *g)
{
	t_coords	dist;
	float		delta_depth;
	float		ray_angle;
	t_iterators	it;

	g->player.map_pos.x = (int)(g->player.pos.x / TILE_SIZE);
	g->player.map_pos.y = (int)(g->player.pos.y / TILE_SIZE);
	ray_angle = g->player.angle - g->constants.half_fov + 0.0001;
	it.i = -1;
	while (++it.i < NUM_RAYS)
	{
		g->rays[it.i].angle = ray_angle;
		g->rays[it.i].sin_a = sin(ray_angle);
		g->rays[it.i].cos_a = cos(ray_angle);
		find_hor_steps(g, it.i, &dist, &delta_depth);
		check_horz_inters(g, it.i, dist, delta_depth);
		find_vert_steps(g, it.i, &dist, &delta_depth);
		check_vert_inters(g, it.i, dist, delta_depth);
		final_inters(g, it.i);
		draw_walls(g, it, ray_angle);
		ray_angle += g->constants.delta_angle;
	}
}

void	update(t_game *g)
{
	static float	ticks_last_frame = 0.0;

	if (ticks_last_frame < 0.5)
		ticks_last_frame = (float) current_time_ms();
	while ((float) current_time_ms()
		- (ticks_last_frame + g->constants.frame_rate) < 0)
		;
	g->delta_time = (float)(current_time_ms() - ticks_last_frame) / 1000.0f;
	ticks_last_frame = (float)current_time_ms();
	player_movement(g);
	raycast(g);
}

int	cub_render(t_game *g)
{
	// static unsigned int	frames = 0;
	// static unsigned int	last_fps = FPS;
	clock_t				elapsed_ticks;

	g->frame.ref = mlx_new_image(g->mlx, g->win.width, g->win.height);
	g->frame.addr = mlx_get_data_addr(g->frame.ref, &g->frame.bpp,
			&g->frame.line_length, &g->frame.endian);
	// frames++;
	elapsed_ticks = clock() - g->start_time;
	if (elapsed_ticks >= CLOCKS_PER_SEC)
	{
		// last_fps = frames;
		// frames = 0;
		g->start_time = clock();
	}
	update(g);
	mlx_put_image_to_window(g->mlx, g->win.ref, g->frame.ref, 0, 0);
	mlx_destroy_image(g->mlx, g->frame.ref);
	return (RETURN_SUCCESS);
}
