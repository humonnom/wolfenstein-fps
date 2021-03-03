#include "cub3d.h"

void		mark_coef(t_info *info, const t_mini *m, int pos, t_list *s)
{
	double	x;
	double	y;
	double	len;
	int		dir;
	int		i;
	t_sprite	*sprite;

	sprite = s->content;
	i = 0;
	x = sprite->coef_x * info->plane.x * m->bsize; 
	y = sprite->coef_x * info->plane.y * m->bsize; 
	len = (fabs(y) == 0) ? fabs(x) : fabs(y);
	while (i++ < len)
	{
		dir = ((x * i / len) - ((y * i / len) * info->win.x)) + pos;
		if (dir > 0 && dir < (info->win.x * m->h) \
			&& (dir % info->win.x) > (pos % info->win.x - m->bsize) \
			&& (dir % info->win.x) < (pos % info->win.x + m->bsize))
			info->img.adr[dir] = RED;
	}
	i = 0;
	x = sprite->coef_y * info->dir.x * m->bsize; 
	y = sprite->coef_y * info->dir.y * m->bsize; 
	len = (fabs(y) == 0) ? fabs(x) : fabs(y);
	while (i++ < len)
	{
		dir = ((x * i / len) - ((y * i / len) * info->win.x)) + pos;
		if (dir > 0 && dir < (info->win.x * m->h) \
			&& (dir % info->win.x) > (pos % info->win.x - m->bsize) \
			&& (dir % info->win.x) < (pos % info->win.x + m->bsize))
			info->img.adr[dir] = BLUE;
	}
}
