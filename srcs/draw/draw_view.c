#include "cub3d.h"
static void	init_view(t_all *s)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.f = 0;
	hit.s = 0;
	s->ray = ray;
	s->hit = hit;
}

void	draw_view(t_all *s, int print)
{
	init_view(s);
	draw_window(s);
	draw_minimap(s);
//	draw_sprite(s);
	if (print)
		mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}
