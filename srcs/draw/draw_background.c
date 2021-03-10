#include "cub3d.h"

static void	fill_range(
			t_info *info,
			int start,
			int end,
			int color)
{
	int i;
	int	y;

	i = -1;
	while (++i < info->win.x)
	{
		y = start - 1;
		while (++y < end)
			info->img.adr[y * info->win.x + i] = color;
	}
}

void		draw_background(t_info *info)
{
	fill_range(info, info->win.y / 2, info->win.y, info->tex.f);
	fill_range(info, 0, info->win.y / 2 + 1, info->tex.c);
}
