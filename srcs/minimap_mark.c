#include "cub3d.h"

int		mark_position(t_all *s, const t_mini *m)
{
	int pos;

	if (!(pos = mark_cur_pos(s, m)))
		return (MARK_ERR);
	return(mark_cur_dir(s, m, pos));
}

int		mark_cur_pos(t_all *s, const t_mini *m)
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

int		mark_cur_dir(t_all *s, const t_mini *m, int pos)
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
	return (DONE);
}
