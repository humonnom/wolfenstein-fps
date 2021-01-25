#include "cub3d.h"

void exit_error(t_game *game, char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
	exit(0);
}

void init_game(t_game *game, int save_mode)
{
	int i;
	init_config(&game->config);
	set_pos(&game->move, 0, 0);
	set_pos(&game->x_move, 0, 0);
	set_pos(&game->rotate, 0, 0);
	game->collected = 0;
	game->options = 0x11111110;
	game->sprites = NULL;
	if (save_mode)
		game->options = game->options | FLAG_SAVE;
	i = 0;
	while (i < TEXTURES)
		game->tex[i++].tex = NULL;
}
