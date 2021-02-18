#include "cub3d.h"

int			mark_user_position(t_all *s, const t_mini *m)
{
	int user_pos;
	int ret;

	ret = (!(user_pos = get_position(s->pos, m->bsize, s->win.x, s->map.h)));
	if (ret == 0)
		draw_circle(s, user_pos, BLUE);
	if (ret == 0)
		return (user_pos);	
	return (ret);
}
