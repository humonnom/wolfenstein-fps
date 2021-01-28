#include "cub3d.h"

void	ft_mark(t_all *s, t_bonus *b)
{
	ft_markpos(s, b);
}

void	ft_markpos(t_all *s, t_bonus *b)
{
	int	pos;
	int pm;
	int	i;
	int	j;

	pos = (int)(b->mini.bsize * s->pos.x + \
		(b->mini.bsize * s->pos.y * s->win.x));
	pm = 3;
	i = -pm;
	while(++i < pm)
	{
		j = -pm;
		while(++j < pm)
			s->img.adr[pos + j + (s->win.x * i)] = BLUE;
	}
	ft_markray(s, b, pos);
}

void	ft_markray(t_all *s, t_bonus *b, int pos)
{
	double	x;
	double	y;
	double	tmp;
	int		ray;
	int		i;

	x = s->ray.x * b->mini.bsize;
	y = s->ray.y * b->mini.bsize;
	tmp = (fabs(y) == 0) ? fabs(x) : fabs(y);
	i = 0;
	while (i++ < tmp)
	{
		ray = (x * i / tmp) + ((y * i / tmp) * s->win.x);
		if ((pos + ray) > 0 && (pos + ray) < (s->win.x * b->mini.h))
			s->img.adr[pos + ray] = YELLOW;
	}
}
