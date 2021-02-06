#include "cub3d.h"

void	draw_view_col(t_all *s, int x)
{
  	set_init(s, x);
	set_step(s);	
	set_dda(s);
	set_range(s);
	set_wall(s, x);
}

void	set_init(t_all *s, int x)
{
	double	tmpx;
	double	tmpy;

	s->map.x = s->pos.x;
	s->map.y = s->pos.y;
	s->hit.f = 0;
	s->hit.s = 0;
	s->cmr.x = 2 * x / (double)(s->win.x) - 1;
	s->ray.x = s->dir.x + s->pla.x * s->cmr.x;
	s->ray.y = s->dir.y + s->pla.y * s->cmr.x;
	tmpx = (sqrt(1 + (s->ray.y * s->ray.y) / (s->ray.x * s->ray.x)));
	tmpy = (sqrt(1 + (s->ray.x * s->ray.x) / (s->ray.y * s->ray.y)));
	s->dst.dx = (s->ray.y == 0) ? 0 : ((s->ray.x == 0) ? 1 : tmpx);
	s->dst.dy = (s->ray.x == 0) ? 0 : ((s->ray.y == 0) ? 1 : tmpy);
}

void	set_step(t_all *s)
{
	if (s->ray.x < 0)
	{
		s->stp.x = -1;
		s->dst.sx = (s->pos.x - s->map.x) * s->dst.dx;
	}
	else
	{
		s->stp.x = 1;
		s->dst.sx = (s->map.x + 1.0 - s->pos.x) * s->dst.dx;
	}
	if (s->ray.y < 0)
	{
		s->stp.y = -1;
		s->dst.sy = (s->pos.y - s->map.y) * s->dst.dy;
	}
	else
	{
		s->stp.y = 1;
		s->dst.sy = (s->map.y + 1.0 - s->pos.y) * s->dst.dy;
	}
}

void	set_dda(t_all *s)
{
	while (s->hit.f == 0)
	{
		if (s->dst.sx < s->dst.sy)
		{
			s->dst.sx += s->dst.dx;
			s->map.x += s->stp.x;
			s->hit.s = 0;
		}
		else
		{
			s->dst.sy += s->dst.dy;
			s->map.y += s->stp.y;
			s->hit.s = 1;
		}
		if (s->map.tab[s->map.y][s->map.x] == '1')
			s->hit.f = 1;
	}
}

void	set_range(t_all *s)
{
	if (s->hit.s == 0)
	{
		s->dst.pw = (s->map.x - s->pos.x + (1 - s->stp.x) / 2);
		s->dst.pw /= s->ray.x;
	}
	else
	{
		s->dst.pw = (s->map.y - s->pos.y + (1 - s->stp.y) / 2); 
		s->dst.pw /= s->ray.y;
	}
	s->scr.lh = (int)(s->win.y / s->dst.pw);
	s->scr.ds = -(s->scr.lh) / 2 + s->win.y / 2;
	s->scr.ds = (s->scr.ds < 0) ? 0 : s->scr.ds;
	s->scr.de = s->scr.lh / 2 + s->win.y / 2;
	s->scr.de = (s->scr.de >= s->win.y) ? s->win.y - 1 : s->scr.de;
}
