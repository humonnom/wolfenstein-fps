#include "cub3d.h"

static void		mark_coef(t_info *info, const t_mini *m, int pos, t_list *s)
{
	double	x;
	double	y;
	double	len;
	int		dir;
	int		i;
	t_sprite	*sprite;

	sprite = s->content;
	x = sprite->coef_x * m->bsize;
	y = sprite->coef_y * m->bsize;
	len = (fabs(y) == 0) ? fabs(x) : fabs(y);
	i = 0;
	while (i++ < len)
	{
		dir = ((x * i / len) - ((y * i / len) * info->win.x)) + pos;
		if (dir > 0 && dir < (info->win.x * m->h) \
			&& (dir % info->win.x) > (pos % info->win.x - m->bsize) \
			&& (dir % info->win.x) < (pos % info->win.x + m->bsize))
			info->img.adr[dir] = RED;
	}
}



int		mark_objects(t_info *info, const t_mini *m)
{
	int user_pos;
	int ret;

	ret = (!(user_pos = mark_user_position(info, m)));
	if (ret == 0)
		mark_direction(info, m, user_pos);
	if (ret == 0)
		mark_coef(info, m, user_pos, info->sprite);
	if (ret == 0)
		ret = mark_sprite(info, m);
	return (ret ? MARK_ERR : 0);
}

