#include "cub3d.h"
static void	init_view(t_info *info)
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
	info->ray = ray;
	info->hit = hit;
}

void	draw_view(t_info *info, int print)
{
	init_view(info);
	draw_window(info);
	draw_sprite_meta(info);
	draw_minimap(info);
	draw_hand(info);
	if (print)
		mlx_put_image_to_window(info->mlx.ptr, info->win.ptr, info->img.ptr, 0, 0);
	free(info->img.ptr);
	free(info->img.adr);
}
