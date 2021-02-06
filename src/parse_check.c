#include "cub3d.h"

int		parse_savecheck(char *arg, char *save)
{
	printf("You need to write save check!!\n");	
	return (0);
}

int		parse_mapcheck(t_all *s)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < s->map.h)
	{
		j = 0;
		while (j < s->map.w)
		{
			if (s->map.tab[i][j] != '1' && i == 0)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && j == 0)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && i == s->map.h - 1)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && j == s->map.w - 1)
				return (ERR);
			j++;
		} 
		i++;
	} 
	return (1);
}

int		parse_check(t_all *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (err_filter(RES_MISSING));
	else if (s->tex.n == NULL || s->tex.s == NULL ||\
			s->tex.e == NULL || s->tex.w == NULL || s->tex.i == NULL )
		return (err_filter(TEX_MISSING));
	else if (s->tex.c == NONE || s->tex.f == NONE)
		return (err_filter(FC_MISSING));
	else if (s->err.p == 0)
		return (err_filter(POS_MISSING));
	else if (s->err.p > 1)
		return (err_filter(POS_DOUBLE));
	else if (parse_mapcheck(s) == -1)
		return (err_filter(MAP_CRACK));
	return (1);
}
