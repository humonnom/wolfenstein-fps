#include "cub3d.h"
#if 1
void	draw_sprite_col(t_info *info, t_sprite *sprite, int x)
{
	int	pixer;
	int dot;	
	int	y;

	y = info->win.y / 2 - sprite->side_len / 2;
	while (++y < info->win.y / 2 + sprite->side_len / 2)
	{
		pixer = RED;
		if (x > sprite->center - 5  && x < sprite->center + 5)
			pixer = BLUE;
		dot = (int)(x + info->win.x * y);
		if (dot < (info->win.x * info->win.y))
			info->img.adr[dot] = pixer;
	}
}
#endif
