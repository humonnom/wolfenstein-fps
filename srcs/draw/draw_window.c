#include "cub3d.h"

void	draw_window(t_info *info)
{
	int		tab[3];
	int		x;

	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.x, info->win.y);
	info->img.adr = (unsigned int *)mlx_get_data_addr(info->img.ptr, &tab[0], &tab[1], &tab[2]);
	draw_background(info);
	x = -1;
	while(++x < info->win.x)
		draw_window_col(info, x);
//	x = -1;
//	while(++x < info->win.x)
//		draw_sprite_col(info, x);
}

