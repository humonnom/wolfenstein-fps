#include "cub3d.h"
int	parse_check(t_info *info)
{
	int	ret;

	ret = 0;
	if (info->win.x <= 0 || info->win.y <= 0)
		ret = RES_MISSING;
	else if (info->tex.n == NULL || info->tex.s == NULL ||\
			info->tex.e == NULL || info->tex.w == NULL || info->tex.i == NULL )
		ret = TEX_MISSING;
	else if (info->tex.c == NONE || info->tex.f == NONE)
		ret = FC_MISSING;
	else if (info->err.p == 0)
		ret = POS_MISSING;
	else if (info->err.p > 1)
		ret = POS_DOUBLE;
	else if (parse_map_check(info))
		ret = MAP_CRACK;
	info->err.n = ret;
	return (ret);
}
