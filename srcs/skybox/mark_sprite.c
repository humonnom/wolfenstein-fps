#include "cub3d.h"

int				mark_sprite(t_info *info, const t_mini *m)
{
	t_list		*cur;
	t_pos		pos;
	t_sprite	*sprite;
	int			sprite_pos;
	int			ret;

	ret = 0;
	cur = info->sprite;
	while (ret == 0 && cur)
	{
		if (!(sprite = cur->content))
			ret = 1;
		else
		{
			pos.x = sprite->x;
			pos.y = sprite->y;
		}
		if (ret == 0)
			ret = (!(sprite_pos = get_position(pos, m->bsize, info->win.x, info->map.h))); 
		if (ret == 0)
			draw_circle(info, sprite_pos, LIGHT_BLUE_GREY);
		cur = cur->next;
	}
	return (ret);
}
