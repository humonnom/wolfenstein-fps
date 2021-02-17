#include "cub3d.h"

void		mark_direction(t_all *s, const t_mini *m, int pos)
{
	double	x;
	double	y;
	double	len;
	int		dir;
	int		i;

	x = s->dir.x * m->bsize;
	y = s->dir.y * m->bsize;
	len = (fabs(y) == 0) ? fabs(x) : fabs(y);
	i = 0;
	while (i++ < len)
	{
		dir = ((x * i / len) - ((y * i / len) * s->win.x)) + pos;
		if (dir > 0 && dir < (s->win.x * m->h) \
			&& (dir % s->win.x) > (pos % s->win.x - m->bsize) \
			&& (dir % s->win.x) < (pos % s->win.x + m->bsize))
			s->img.adr[dir] = YELLOW;
	}
}

