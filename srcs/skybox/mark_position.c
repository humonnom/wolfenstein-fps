#include "cub3d.h"

int		mark_position(t_all *s, const t_mini *m)
{
	int pos;
	int pm;
	int	i;
	int	j;

	pos = (int)(s->pos.x * m->bsize) + \
			(int)((s->map.h - s->pos.y) * m->bsize) * s->win.x;
	pm = 3;
	i = -pm;
	while(++i < pm)
	{
		j = -pm;
		while(++j < pm)
			s->img.adr[pos + j + (s->win.x * i)] = BLUE;
	}
	return (pos);
}
