#include "cub3d.h"

/*******************************************
-function:	
-ar:	s 		->	structure(t_all)
-return: non
-call:	ft_ray()
		ft_dir()
		ft_ver()
		ft_hor()
		ft_stock()
		ft_column()
		ft_size()
		ft_sprite()
 *******************************************/
void	ft_screen(t_all *s)
{
	int		bpp;
	int		sl;
	int		end;
	int		x;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &bpp, &sl, &end);
	s->stk = malloc(sizeof(t_stk) * s->win.x);
	x = 0;
	pxy(dir);
	while(x < s->win.x)
	{
		if (x == 0 || x == s->win.x /2 || x == s->win.x -1)
		//if (x == s->win.x -1)
		{
			ft_set(s, x);
			ft_ray(s);	
			ft_dda(s);
			ft_dst(s);
			pxy(ray);
			ft_minimap(s);
		}
		//ft_vertical(s, x);
		x++;
	}
	ft_time(s);
	//ft_sprite(s);
}

void	ft_set(t_all *s, int x)
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

void	ft_ray(t_all *s)
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

void	ft_dda(t_all *s)
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
		if (s->map.tab[s->map.x][s->map.y] == '1')
			s->hit.f = 1;
	}
}
void	ft_dst(t_all *s)
{
	if (s->hit.s == 0)
	{
		s->dst.pw = ((s->map.x - s->pos.x) + (1 - s->stp.x) / 2);
		s->dst.pw /= s->ray.x;
	}
	else
	{
		s->dst.pw = (s->map.y - s->pos.y + (1 - s->stp.y) / 2); 
		s->dst.pw /= s->ray.y;
	}
	s->scr.lh = (int)(s->win.y / s->dst.pw);
	s->scr.ds = -(s->scr.lh) / 2 + s->win.y / 2;
	if (s->scr.de < 0)
		s->scr.ds = 0;
	s->scr.de = s->scr.lh / 2 + s->win.y / 2;
	if (s->scr.de >= s->win.y)
		s->scr.de = s->win.y - 1;
}

void	ft_vertical(t_all *s, int x)
{
	int h;
	unsigned int color;

	h = s->scr.ds;
	color = s->hit.s ? BLUE/2 : RED; 
	while (++h < s->scr.de)
		s->img.adr[(s->win.x * h) + x] = color;
}

void	ft_time(t_all *s)
{
	s->tim.old = s->tim.now;
	s->tim.now = clock();
	s->tim.frame = (s->tim.now - s->tim.old) / 1000.0;
	s->tim.ms = SPEED;//s->tim.frame * 5.0;	
	s->tim.rs = TURN;//s->tim.frame * 3.0;	
}
