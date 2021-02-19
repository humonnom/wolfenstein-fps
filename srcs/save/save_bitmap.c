#include "cub3d.h"

int		save_bitmap(t_all *s)
{
	int ret;

	ret = 0;
	draw_view(s, NON_PRINT);
	make_bitmap_file(s);
	exit_game(s, 0);
	return (ret);
} 


