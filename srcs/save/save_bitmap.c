#include "cub3d.h"

int		save_bitmap(t_info *info)
{
	int ret;

	ret = 0;
	draw_view(info, NON_PRINT);
	make_bitmap_file(info);
	exit_game(info, 0);
	return (ret);
} 


