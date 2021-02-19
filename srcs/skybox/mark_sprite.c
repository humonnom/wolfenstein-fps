#include "cub3d.h"

int				mark_sprite(t_info *info, const t_mini *m)
{
	t_pos	pos;
	int		sprite_pos;
	int		sprite_num;
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	sprite_num = info->map.sprite;
	while (++i < sprite_num && ret == 0)
	{
		if (!(pos.x = info->sprite[i].x) || !(pos.y = info->sprite[i].y))
			ret = 1;
		if (ret == 0)
			ret = (!(sprite_pos = get_position(pos, m->bsize, info->win.x, info->map.h))); 
		if (ret == 0)
			draw_circle(info, sprite_pos, LIGHT_BLUE_GREY);
	}
	return (ret);
}
