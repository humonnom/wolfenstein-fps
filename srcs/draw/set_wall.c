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

static void		get_wall_info(t_all *s, t_wall *w)
{
	if (s->hit.s == 0)
		w->wallx = s->pos.y + s->dist.pw * s->ray.y;
	else
		w->wallx = s->pos.x + s->dist.pw * s->ray.x;
	w->wallx -= (int)w->wallx;
	w->tex_x = (int)(w->wallx * (double)(PIXEL_SIZE));
	if (s->hit.s == 0 && s->ray.x > 0)
		w->tex_x = PIXEL_SIZE - w->tex_x - 1;
	if (s->hit.s == 1 && s->ray.y < 0)
		w->tex_x = PIXEL_SIZE - w->tex_x - 1;
	w->step = 1.0 * PIXEL_SIZE / s->screen.lh;
	w->texpos = (s->screen.ds - s->win.y / 2 + s->screen.lh / 2) * w->step;
	
	w->texture_x = (s->ray.x < 0) ? s->tex.w : s->tex.e;
	w->texture_y = (s->ray.y < 0) ? s->tex.s : s->tex.n;
}

void	set_wall(t_all *s, int x)
{
	unsigned int pixel;
	t_wall	w;
	int		y;

	y = s->screen.ds - 1;
	pixel = s->hit.s ? BLUE/2 : RED;
	while (++y < s->screen.de)
		s->img.adr[(s->win.x * y) + x] = pixel;
	init_wall(&w);
	get_wall_info(s, &w);
	y = s->screen.ds - 1;
	while (++y < s->screen.de)
	{
		w.tex_y = (int)w.texpos & (PIXEL_SIZE - 1);
		w.texpos += w.step;
		if (s->hit.s == 0)
			pixel = w.texture_x[PIXEL_SIZE * w.tex_y + w.tex_x];
		if (s->hit.s == 1)
			pixel = w.texture_y[PIXEL_SIZE * w.tex_y + w.tex_x];
		s->img.adr[y * s->win.x + x] = pixel;
	}
}
