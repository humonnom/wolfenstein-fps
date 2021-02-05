#include "cub3d.h"

void	draw_window(t_all *s)
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
	get_3d(s);
	mlx_put_image_to_window(s->mlx.ptr, s->win.ptr, s->img.ptr, 0, 0);
	free(s->img.ptr);
	free(s->img.adr);
}

int		cub3d_loop(t_all s, char *cub, int save)
{
	s.mlx.ptr = mlx_init();
	if (ft_parse(&s, cub) == -1)
		return (ft_close(&s, 0));
//	if (save == 1)
//		return (ft_bitmap(&s));
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	draw_window(&s);
	mlx_hook(s.win.ptr, KEY, 0, ft_key, &s);	
	mlx_hook(s.win.ptr, EXIT_BTN, 0, ft_close, &s);	
	mlx_loop(s.mlx.ptr);
	return (1);
}
