#include "cub3d.h"

int				mark_sprite(t_all *s, const t_mini *m)
{
	t_pos	pos;
	int		sprite_pos;
	int		sprite_num;
	int		i;
	int		ret;

	ret = 0;
	i = -1;
	sprite_num = s->map.sprite;
	while (++i < sprite_num && ret == 0)
	{
		if (!(pos.x = s->sprite[i].x) || !(pos.y = s->sprite[i].y))
			ret = 1;
		if (ret == 0)
			ret = (!(sprite_pos = get_position(pos, m->bsize, s->win.x, s->map.h))); 
		if (ret == 0)
			draw_circle(s, sprite_pos, WHITE);
	}
	return (ret);
}
