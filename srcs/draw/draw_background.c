#include "cub3d.h"
static void	fill_color_range(t_info *info, int type)
{
	int start;
	int	end;
	int color;
	int i;

	start = (type == FLOOR) ? info->win.y/2 - 1 : -1;
	end = (type == FLOOR) ? info->win.y : info->win.y/2 - 1;
	color = (type == FLOOR) ? info->tex.f : info->tex.c;
	while (++start <= end)
	{
		i = -1;
//		while (++i < info->win.x)
//			info->img.adr[start * info->win.x + i] = color;
	}
}

void		draw_background(t_info *info)
{
	fill_color_range(info, FLOOR);
	fill_color_range(info, CEILING);
}
