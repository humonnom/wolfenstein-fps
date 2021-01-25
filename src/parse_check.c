#include "cub3d.h"

int		ft_savecheck(char *arg, char *save)
{
	printf("You need to write save check!!\n");	
	return (0);
}

/*******************************************
-function: check parsed map
-ar:	s 		->	structure(t_all)
-return: -1(return value of ft_strerr) of 1
-call:	ft_strerr()
 		ft_mapcheck()
 *******************************************/
int		ft_mapcheck(t_all *s)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < s->map.y)
	{
		j = 0;
		while (j < s->map.x)
		{
			if (s->map.tab[i][j] != '1' && i == 0)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && j == 0)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && i == s->map.y - 1)
				return (ERR);
			else if (s->map.tab[i][j] != '1' && j == s->map.x - 1)
				return (ERR);
			j++;
		} 
		i++;
	} 
	return (1);
}

/*******************************************
-function: check parsed info 
-ar:	s 		->	structure(t_all)
-return: -1(return value of ft_strerr) of 1
-call:	ft_strerr()
 		ft_mapcheck()
 *******************************************/
int		ft_parcheck(t_all *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (ft_strerr(RES_MISSING));
	else if (s->tex.n == NULL || s->tex.s == NULL ||\
			s->tex.e == NULL || s->tex.w == NULL || s->tex.i == NULL )
		return (ft_strerr(TEX_MISSING));
	else if (s->tex.c == NONE || s->tex.f == NONE)
		return (ft_strerr(FC_MISSING));
	else if (s->err.p == 0)
		return (ft_strerr(POS_MISSING));
	else if (s->err.p > 1)
		return (ft_strerr(POS_DOUBLE));
	else if (ft_mapcheck(s) == -1)
		return (ft_strerr(MAP_CRACK));
	return (1);
}
