#include "cub3d.h"

static void init_wall(t_wall *w)
{
	w->texture_x = NULL;
	w->texture_y = NULL;
	w->wallx = 0;
	w->step = 0;
	w->texpos = 0;
	w->tex_x = 0;
	w->tex_y = 0;
}

static void		get_wall_info(t_info *info, t_wall *w)
{
	if (info->hit.s == 0)
		w->wallx = info->pos.y + info->dist.pw * info->ray.y;
	else
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

void	set_wall(t_info *info, int x)
{
	unsigned int pixel;
	t_wall	w;
	int		y;

	y = info->screen.ds - 1;
	pixel = info->hit.s ? BLUE/2 : RED;
	while (++y < info->screen.de)
		info->img.adr[(info->win.x * y) + x] = pixel;
	init_wall(&w);
	get_wall_info(info, &w);
	y = info->screen.ds - 1;
	while (++y < info->screen.de)
	{
		w.tex_y = (int)w.texpos & (PIXEL_SIZE - 1);
		w.texpos += w.step;
		if (info->hit.s == 0)
			pixel = w.texture_x[PIXEL_SIZE * w.tex_y + w.tex_x];
		if (info->hit.s == 1)
			pixel = w.texture_y[PIXEL_SIZE * w.tex_y + w.tex_x];
		info->img.adr[y * info->win.x + x] = pixel;
	}
}
