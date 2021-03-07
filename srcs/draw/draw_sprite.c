#include "cub3d.h"

int	draw_sprite(t_info *info, t_sprite *sprite)
{
	int x;
	int spr_x;
	
	x = -1;
	while (++x < info->win.x)
	{
		if (x >= sprite->draw_start && x < sprite->draw_end)
		{
			spr_x = x - sprite->draw_start;
			if (info->zbuf[x] > sprite->dist && spr_x >= 0)
			{
				draw_sprite_col(info, sprite, x, spr_x);
			}
		}
	}
	return (0);
}

