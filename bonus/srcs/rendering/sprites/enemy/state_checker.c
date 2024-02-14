#include "maze.h"

bool	is_enemy(int type)
{
	return ((type >= OBJECT_SOLDIER_WALK && type <= OBJECT_SOLDIER_DEATH)
		|| (type >= OBJECT_CYBERDEMON_WALK && type <= OBJECT_CYBERDEMON_DEATH)
		|| (type >= OBJECT_CACODEMON_WALK && type <= OBJECT_CACODEMON_DEATH));
}

bool	is_enemy_walking(int type)
{
	return (type == OBJECT_SOLDIER_WALK
		|| type == OBJECT_CYBERDEMON_WALK
		|| type == OBJECT_CACODEMON_WALK);
}

bool	is_enemy_attacking(int type)
{
	return (type == OBJECT_SOLDIER_ATTACK
		|| type == OBJECT_CYBERDEMON_ATTACK
		|| type == OBJECT_CACODEMON_ATTACK);
}

bool	is_enemy_damaged(int type)
{
	return (type == OBJECT_SOLDIER_DAMAGED
		|| type == OBJECT_CYBERDEMON_DAMAGED
		|| type == OBJECT_CACODEMON_DAMAGED);
}

bool	is_enemy_dead(int type)
{
	return (type == OBJECT_SOLDIER_DEATH
		|| type == OBJECT_CYBERDEMON_DEATH
		|| type == OBJECT_CACODEMON_DEATH);
}
