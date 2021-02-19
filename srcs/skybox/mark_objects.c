#include "cub3d.h"

int		mark_objects(t_info *info, const t_mini *m)
{
	int user_pos;
	int ret;

	ret = (!(user_pos = mark_user_position(info, m)));
	if (ret == 0)
		mark_direction(info, m, user_pos);
	if (ret == 0)
		ret = mark_sprite(info, m);
	return (ret ? MARK_ERR : 0);
}

