#include "cub3d.h"

void	init_view(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	s->ray = ray;
	s->hit = hit;
}

void	set_time(t_all *s)
{
	s->tim.old = s->tim.now;
	s->tim.now = clock();
	s->tim.frame = (s->tim.now - s->tim.old) / 1000.0;
	s->tim.ms = SPEED;//s->tim.frame * 5.0;	
	s->tim.rs = TURN;//s->tim.frame * 3.0;	
}

void	draw_view(t_all *s)
{
	int		tab[3];
	int		x;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &tab[0], &tab[1], &tab[2]);
	x = -1;
	while(++x < s->win.x)
		draw_view_col(s, x);
	draw_minimap(s);
//	draw_sprite(s);
	set_time(s);
}

void	draw_window(t_all *s)
{
	init_view(s);
	draw_view(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}
