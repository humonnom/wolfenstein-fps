#include "cub3d.h"
#if 0
static void	set_range(t_info *info)
{
	if (info->hit.s == 0)
	{
		info->dist.pw = (info->map.x - info->pos.x + (1 - info->step.x) / 2);
		info->dist.pw /= info->ray.x;
	}
	else
	{
		info->dist.pw = (info->map.y - info->pos.y + (1 - info->step.y) / 2); 
		info->dist.pw /= info->ray.y;
	}
	info->screen.lh = (int)(info->win.y / info->dist.pw);
	info->screen.ds = -(info->screen.lh) / 2 + info->win.y / 2;
	info->screen.ds = (info->screen.ds < 0) ? 0 : info->screen.ds;
	info->screen.de = info->screen.lh / 2 + info->win.y / 2;
	info->screen.de = (info->screen.de >= info->win.y) ? info->win.y - 1 : info->screen.de;
}
#endif
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

static int	get_drawing_sprite_info(t_info *info, t_sprite *sprite)
{
//	int i;
//	double	draw_start_x;
//	double	draw_end_x;
	double	sprite_center_x;
//	double	sray_dir;
	//distance -> get ds, de(scale)
	//position -> get sprite_center_x
	sprite_center_x = sprite->coef_x * (info->win.x / 2);
	return (sprite_center_x);
}

void	draw_sprite(t_info *info, t_sprite *sprite)
{
		//if sprite in the screen, draw sprite;
	//tmp draw red rect
	draw_rect_window(info, get_drawing_sprite_info(info, sprite), RED, 100);
#if 0
	draw sprite
//	while (draw_start_x ~ draw_end_x)
	{
		draw_sprite_col(info, sprite);
	}
#endif
}
