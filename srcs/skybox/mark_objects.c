#include "cub3d.h"

int		mark_objects(t_all *s, const t_mini *m)
{
	int user_pos;
	int ret;

	ret = (!(user_pos = mark_user_position(s, m)));
	if (ret == 0)
		mark_direction(s, m, user_pos);
	if (ret == 0)
		ret = mark_sprite(s, m);
	return (ret ? MARK_ERR : 0);
}

