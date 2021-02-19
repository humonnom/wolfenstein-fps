#include "cub3d.h"
int	get_position(t_pos pos, int bsize, int win_x, int map_h)
{
	int position;

	position = (int)(pos.x * bsize) + \
			(int)((map_h - pos.y) * bsize) * win_x;
	return (position);
}

void draw_circle(t_info *info, int pos, int color)
{
	int pm;
	int	i;
	int	j;
	
	pm = 3;
	i = -pm;
	while(++i < pm)
	{
		j = -pm;
		while(++j < pm)
			info->img.adr[pos + j + (info->win.x * i)] = color;
	}
}

