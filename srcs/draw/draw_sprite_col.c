#include "cub3d.h"

void	draw_sprite_col(
		t_info *info,
		t_sprite *sprite,
		int x,
		int spr_x)
{
	int	pixel;
	int	dot;
	int	center;
	int	spr_y;
	int	y;

	center = info->win.y / 2;
	y = (center - sprite->side_len / 2) - 1;
	if (y < 0)
		y = -1;
	spr_y = -1;
	while (++y < center + sprite->side_len / 2)
	{
		++spr_y;
		dot = (int)(x + info->win.x * y);
		pixel = (int)(spr_x * sprite->tex_step) + \
				(int)(spr_y * sprite->tex_step) * PIXEL_SIZE;
		if (x < info->win.x && y < info->win.y && \
				pixel < pow(PIXEL_SIZE, 2))
		{
			if (info->tex.i[pixel] != NONE)
				info->img.adr[dot] = info->tex.i[pixel];
		}
	}
}
