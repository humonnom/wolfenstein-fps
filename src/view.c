#include "cub3d.h"

void	init_view(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	s->ray = ray;
	s->hit = hit;
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
}

void	draw_window(t_all *s)
{
	init_view(s);
	draw_view(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}
