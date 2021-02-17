#include "cub3d.h"

int		mark_objects(t_all *s, const t_mini *m)
{
	int pos;
	int ret;

	ret = 0;
	if (!(pos = mark_position(s, m)))
		ret = MARK_ERR;
	else
	{
		mark_direction(s, m, pos);
	}
	return (ret);
}

