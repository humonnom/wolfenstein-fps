#include "cub3d.h"

void	draw_window(t_all *s)
{
	int		tab[3];
	int		x;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &tab[0], &tab[1], &tab[2]);
	x = -1;
	while(++x < s->win.x)
		draw_window_col(s, x);
}

