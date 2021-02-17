#include "cub3d.h"

static void	set_init(t_all *s, int x)
{
	double	tmpx;
	double	tmpy;

	s->map.x = s->pos.x;
	s->map.y = s->pos.y;
	s->hit.f = 0;
	s->hit.s = 0;
	s->camera.x = 2 * x / (double)(s->win.x) - 1;
	s->ray.x = s->dir.x + s->plane.x * s->camera.x;
	s->ray.y = s->dir.y + s->plane.y * s->camera.x;
	tmpx = (sqrt(1 + (s->ray.y * s->ray.y) / (s->ray.x * s->ray.x)));
	tmpy = (sqrt(1 + (s->ray.x * s->ray.x) / (s->ray.y * s->ray.y)));
	s->dist.dx = (s->ray.y == 0) ? 0 : ((s->ray.x == 0) ? 1 : tmpx);
	s->dist.dy = (s->ray.x == 0) ? 0 : ((s->ray.y == 0) ? 1 : tmpy);
}

static void	set_step(t_all *s)
{
	if (s->ray.x < 0)
	{
		s->step.x = -1;
		s->dist.sx = (s->pos.x - s->map.x) * s->dist.dx;
	}
	else
	{
		s->step.x = 1;
		s->dist.sx = (s->map.x + 1.0 - s->pos.x) * s->dist.dx;
	}
	if (s->ray.y < 0)
	{
		s->step.y = -1;
		s->dist.sy = (s->pos.y - s->map.y) * s->dist.dy;
	}
	else
	{
		s->step.y = 1;
		s->dist.sy = (s->map.y + 1.0 - s->pos.y) * s->dist.dy;
	}
}

static void	set_dda(t_all *s)
{
	while (s->hit.f == 0)
	{
		if (s->dist.sx < s->dist.sy)
		{
			s->dist.sx += s->dist.dx;
			s->map.x += s->step.x;
			s->hit.s = 0;
		}
		else
		{
			s->dist.sy += s->dist.dy;
			s->map.y += s->step.y;
			s->hit.s = 1;
		}
		if (s->map.tab[s->map.y][s->map.x] == '1')
			s->hit.f = 1;
	}
}

static void	set_range(t_all *s)
{
	if (s->hit.s == 0)
	{
		s->dist.pw = (s->map.x - s->pos.x + (1 - s->step.x) / 2);
		s->dist.pw /= s->ray.x;
	}
	else
	{
		s->dist.pw = (s->map.y - s->pos.y + (1 - s->step.y) / 2); 
		s->dist.pw /= s->ray.y;
	}
	s->screen.lh = (int)(s->win.y / s->dist.pw);
	s->screen.ds = -(s->screen.lh) / 2 + s->win.y / 2;
	s->screen.ds = (s->screen.ds < 0) ? 0 : s->screen.ds;
	s->screen.de = s->screen.lh / 2 + s->win.y / 2;
	s->screen.de = (s->screen.de >= s->win.y) ? s->win.y - 1 : s->screen.de;
}

void	draw_window_col(t_all *s, int x)
{
  	set_init(s, x);
	set_step(s);	
	set_dda(s);
	set_range(s);
	set_wall(s, x);
}
