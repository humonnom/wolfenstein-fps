#include "cub3d.h"
static int		parse_mapcheck(t_info *info)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < info->map.h)
	{
		j = 0;
		while (j < info->map.w)
		{
			if (info->map.tab[i][j] != '1' && i == 0)
				return (ERR);
			else if (info->map.tab[i][j] != '1' && j == 0)
				return (ERR);
			else if (info->map.tab[i][j] != '1' && i == info->map.h - 1)
				return (ERR);
			else if (info->map.tab[i][j] != '1' && j == info->map.w - 1)
				return (ERR);
			j++;
		} 
		i++;
	} 
	return (1);
}

int		parse_check(t_info *info)
{
	if (info->win.x <= 0 || info->win.y <= 0)
		return (err_filter(RES_MISSING));
	else if (info->tex.n == NULL || info->tex.s == NULL ||\
			info->tex.e == NULL || info->tex.w == NULL || info->tex.i == NULL )
		return (err_filter(TEX_MISSING));
	else if (info->tex.c == NONE || info->tex.f == NONE)
		return (err_filter(FC_MISSING));
	else if (info->err.p == 0)
		return (err_filter(POS_MISSING));
	else if (info->err.p > 1)
		return (err_filter(POS_DOUBLE));
	else if (parse_mapcheck(info) == -1)
		return (err_filter(MAP_CRACK));
	return (1);
}
