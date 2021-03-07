#include "cub3d.h"

void	draw_sprite_col(t_info *info, t_sprite *sprite, int x, int spr_x)
{
	int	pixel;
	int	pixel_x;
	int	pixel_y;
	int	center;
	int dot;	
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
		pixel_y = spr_y * sprite->tex_step;
		pixel_x = spr_x * sprite->tex_step;
		pixel = (int)pixel_x + (int)pixel_y * PIXEL_SIZE;
		dot = (int)(x + info->win.x * y);
		if (x < info->win.x && y < info->win.y && pixel < pow(PIXEL_SIZE, 2))
		{
		//	if (info->tex.i[pixel] != 0)
			info->img.adr[dot] = info->tex.i[pixel]; 
		}
	}
}

#if 0
			if (y == center + sprite->side_len / 2 - 1)
			{
			pd(spr_x);
			pd(spr_y);
				ps("======================\n");
				pd(pixel);
				pd(PIXEL_SIZE);
				pf(sprite->side_len);
				pf(sprite->tex_scale);
				pf(sprite->tex_step);
			}
//static void init_wall(t_wall *w)
//{
//	w->texture_x = NULL;
//	w->texture_y = NULL;
//	w->wallx = 0;
//	w->step = 0;
//	w->texpos = 0;
//	w->tex_x = 0;
//	w->tex_y = 0;
//}

static void		get_sprite_info(t_sprite *sprite)
{
	w->wallx = info->pos.y + info->dist.pw * info->ray.y;
	w->wallx = info->pos.x + info->dist.pw * info->ray.x;
	w->wallx -= (int)w->wallx;
	w->tex_x = (int)(w->wallx * (double)(PIXEL_SIZE));
	if (info->hit.s == 0 && info->ray.x > 0)
		w->tex_x = PIXEL_SIZE - w->tex_x - 1;
	if (info->hit.s == 1 && info->ray.y < 0)
		w->tex_x = PIXEL_SIZE - w->tex_x - 1;
	w->step = 1.0 * PIXEL_SIZE / info->screen.lh;
	w->texpos = (info->screen.ds - info->win.y / 2 + info->screen.lh / 2) * w->step;
	w->texture_x = (info->ray.x < 0) ? info->tex.w : info->tex.e;
	w->texture_y = (info->ray.y < 0) ? info->tex.s : info->tex.n;
}

void	draw_sprite_col(t_info *info, t_sprite *sprite, int x, int spr_x)
{
	unsigned int pixel;
	int		y;

//	init_wall(&w);
	get_sprite_info(sprite);
	y = info->screen.ds - 1;
	while (++y < info->screen.de)
	{
		w.tex_y = (int)w.texpos & (PIXEL_SIZE - 1);
		w.texpos += w.step;
		pixel = w.texture_i[PIXEL_SIZE * w.tex_y + w.tex_x];
		info->img.adr[y * info->win.x + x] = pixel;
	}
}
#endif
