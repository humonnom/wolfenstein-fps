#include "cub3d.h"
#if 0
void draw_rect_window(t_info *info, double x, int color, int width)
{
	int pos;
	int pm;
	int	i;
	int	j;
	
	pm = width / 2;
	i = -pm;
	pos = (info->win.x * (info->win.y / 2)) + (info->win.x / 2) + x;
	while(++i < pm)
	{
		j = -pm;
		while(++j < pm)
			info->img.adr[pos + j + (info->win.x * i)] = color;
	}
}

static int	draw_sprite_col_tmp
			(t_info	*info,
			double draw_start,
			double draw_end,
			double sprite_center,
			double sprite_side_len)
{
		int i = 0;
		while (++i < info->win.y)
		{
			double center = info->win.x/2 + sprite_center + (i * info->win.x);
			double start = info->win.x/2 + draw_start + (i * info->win.x);
			double end = info->win.x/2 + draw_end + (i * info->win.x);
			info->img.adr[(int)center] = BLUE;
			info->img.adr[(int)start] = RED;
			info->img.adr[(int)end] = RED;
		}
}
#endif

void	draw_sprite(t_info *info, t_sprite *sprite)
{

	int x = 0;
	while (++x < info->win.x)
	{
		if (x > sprite->draw_start && x < sprite->draw_end)
			draw_sprite_col(info, sprite, x);
	}
#if 0
	//draw_sprite_col_tmp(info, draw_start, draw_end, sprite_center, sprite_side_len);
	//tmp draw red rect
	//draw_rectwindow(info, get_drawing_sprite_info(info, sprite), RED, 100);
	draw sprite
//	while (draw_start_x ~ draw_end_x)
	{
	}
#endif
}
