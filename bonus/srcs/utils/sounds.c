#include "maze.h"

void	init_sounds(t_game *g)
{
	g->sound[SOUND_THEME].path = " assets/sounds/theme.wav";
	g->sound[SOUND_THEME].volume = "0.7";
	g->sound[SOUND_NPC_ATTACK].path = " assets/sounds/effects/npc_attack.wav";
	g->sound[SOUND_NPC_ATTACK].volume = "1";
	g->sound[SOUND_NPC_DEATH].path = " assets/sounds/effects/npc_death.wav";
	g->sound[SOUND_NPC_DEATH].volume = "1";
	g->sound[SOUND_NPC_DAMAGED].path = " assets/sounds/effects/npc_pain.wav";
	g->sound[SOUND_NPC_DAMAGED].volume = "1";
	g->sound[SOUND_PLAYER_DAMAGED].path
		= " assets/sounds/effects/player_pain.wav";
	g->sound[SOUND_PLAYER_DAMAGED].volume = "2";
	g->sound[SOUND_SHOTGUN].path = " assets/sounds/effects/shotgun.wav";
	g->sound[SOUND_SHOTGUN].volume = "1";
	g->sound[SOUND_DOOR_CLOSE].path = " assets/sounds/effects/door_close.wav";
	g->sound[SOUND_DOOR_CLOSE].volume = "1";
	g->sound[SOUND_DOOR_OPEN].path = " assets/sounds/effects/door_open.wav";
	g->sound[SOUND_DOOR_OPEN].volume = "1";
	g->sound[SOUND_SHOTGUN_SWITCH].path
		= " assets/sounds/effects/shotgun_switch.wav";
	g->sound[SOUND_SHOTGUN_SWITCH].volume = "1";
	g->sound[SOUND_KNIFE].path = " assets/sounds/effects/knife.wav";
	g->sound[SOUND_KNIFE].volume = "1";
	g->sound[SOUND_KNIFE_SWITCH].path
		= " assets/sounds/effects/knife_switch.wav";
	g->sound[SOUND_KNIFE_SWITCH].volume = "1";
}

int	afplay(t_game *g, int sound)
{
	char	*command;
	char	*tmp;
	char	**afplays;

	afplays = (char *[]){"afplay -v ", g->sound[sound].volume,
		g->sound[sound].path, NULL};
	command = ft_strjoin(afplays[0], afplays[1]);
	if (!command)
		return (errors_setter(g, ERR_MALLOC));
	tmp = command;
	command = ft_strjoin(command, afplays[2]);
	if (!command)
		return (errors_setter(g, ERR_MALLOC));
	free(tmp);
	system(command);
	free(command);
	return (RETURN_SUCCESS);
}

void	play_sound_track(t_game *g)
{
	g->pid.soundtrack = fork();
	if (g->pid.soundtrack == -1)
		errors_exit(g, ERR_FORK);
	if (g->pid.soundtrack == 0)
	{
		while (access(TMP, F_OK) == -1)
			if (afplay(g, SOUND_THEME))
				errors_exit(g, g->error.message);
		exit(EXIT_SUCCESS);
	}
}

void	play_sound_effect(t_game *g, int sound)
{
	int	i;

	i = -1;
	while (g->pid.playing_soundeffect[++i] && i < 5)
		;
	if (i == 5)
		return ;
	g->pid.soundeffect[i] = fork();
	if (g->pid.soundeffect[i] == -1)
		errors_exit(g, ERR_FORK);
	if (g->pid.soundeffect[i] == 0)
	{
		g->pid.playing_soundeffect[i] = getpid();
		if (afplay(g, sound))
			errors_exit(g, g->error.message);
		g->pid.playing_soundeffect[i] = 0;
		exit(EXIT_SUCCESS);
	}
}

void	stop_sound_track(t_game *g)
{
	if (!g->allocated.soundtrack)
		return ;
	system("killall afplay");
	g->allocated.soundtrack = false;
	kill(g->pid.soundtrack, SIGKILL);
}
