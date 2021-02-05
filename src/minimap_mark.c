#include "cub3d.h"

void	ft_mark(t_all *s, const t_mini *m)
{
	ft_markpos(s, m);
}

void	ft_markpos(t_all *s, const t_mini *m)
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
	ft_markray(s, m, pos);
}

void	ft_markray(t_all *s, const t_mini *m, int pos)
{
	double	x;
	double	y;
	double	tmp;
	int		ray;
	int		i;

	x = s->dir.x * m->bsize;
	y = s->dir.y * m->bsize;
	tmp = (fabs(y) == 0) ? fabs(x) : fabs(y);
	i = 0;
	while (i++ < tmp)
	{
		ray = (x * i / tmp) - ((y * i / tmp) * s->win.x);
		if ((pos + ray) > 0 && (pos + ray) < (s->win.x * m->h))
			s->img.adr[pos + ray] = YELLOW;
	}
}
