#include "cub3d.h"

int			mark_user_position(t_info *info, const t_mini *m)
{
	int user_pos;
	int ret;

	ret = (!(user_pos = get_position(info->pos, m->bsize, info->win.x, info->map.h)));
	if (ret == 0)
		draw_circle(info, user_pos, BLUE);
	if (ret == 0)
		return (user_pos);	
	return (ret);
}
