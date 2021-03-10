#include "cub3d.h"

int		save_bitmap(t_info *info)
{
	int ret;

	ret = 0;
	draw_view(info, NON_PRINT);
	if ((make_bitmap_file(info)))
		report_err(FILE_OPEN);
	exit_game(info, 0);
	return (ret);
} 


