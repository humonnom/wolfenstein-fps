#include "cub3d.h"
int	parse_check(t_info *info)
{
	if (info->win.x <= 0 || info->win.y <= 0)
		return (report_err(RES_MISSING));
	else if (info->tex.n == NULL || info->tex.s == NULL ||\
			info->tex.e == NULL || info->tex.w == NULL || info->tex.i == NULL )
		return (report_err(TEX_MISSING));
	else if (info->tex.c == NONE || info->tex.f == NONE)
		return (report_err(FC_MISSING));
	else if (info->err.p == 0)
		return (report_err(POS_MISSING));
	else if (info->err.p > 1)
		return (report_err(POS_DOUBLE));
	else if (parse_map_check(info))
		return (report_err(MAP_CRACK));
	return (0);
}
