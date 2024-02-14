#include "maze.h"

typedef struct timespec	t_timespec;

t_ull	current_time_ms(void)
{
	t_timespec	now;

	clock_gettime(CLOCK_MONOTONIC, &now);
	return (now.tv_sec * 1000 + now.tv_nsec / 1000000);
}
