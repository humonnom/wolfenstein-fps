#include "cub3d.h"

/*******************************************
-function:  parse resolution
-ar:	s			-> structure(t_all)
		line		-> each line
		i			-> index
-return: err number of 0
-call:	ft_atoiskip()
		ft_spaceskip()
 *******************************************/
int		ft_res(t_all *s, char *line, int *i)
{
	if (s->win.x != 0 || s->win.y != 0)
		return (RES_DOUBLE);
	(*i)++;
	s->win.x = ft_atoiskip(line, i);
	s->win.y = ft_atoiskip(line, i);
	if (s->win.x > 2560)
		s->win.x = 2560;
	if (s->win.y > 1400)
		s->win.y = 1400;
	ft_spaceskip(line, i);
	if (s->win.x <= 0 || s->win.y <= 0 || line[*i] != '\0')
		return (RES_INV);
	return (0);	
}

/*******************************************
-function:  parse color
-ar:	color		-> color pointer
		line		-> each line
		i			-> index
-return: err number of 0
-call:	ft_atoiskip()
		ft_spaceskip()
 *******************************************/
int		ft_colors(unsigned int *color, char *line, int *i)
{
	int	r;
	int	g;
	int	b;

	if (*color != NONE)
		return (FC_DOUBLE);
	(*i)++;
	r = ft_atoiskip(line, i);
	(*i)++;
	g = ft_atoiskip(line, i);
	(*i)++;
	b = ft_atoiskip(line, i);
	ft_spaceskip(line, i);
	if (line[*i] != '\0' || r > 255 || g > 255 || b > 255)
		return (FC_INV);
	*color = r * 256 * 256 + g * 256 + b;
	return (0);
}

/*******************************************
-function: parse pos 
-ar:	s 		->	structure(t_all)
-return: non 
-call: non
 *******************************************/
void	ft_pos(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < s->map.h)
	{
		while (++j < s->map.w)
		{
			c = s->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				s->pos.y = (double)i + 0.5;
				s->pos.x = (double)j + 0.5;
				s->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				s->dir.x *= (c == 'W') ? -1 : 1;
				s->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				s->dir.y *= (c == 'N') ? -1 : 1;
				s->err.p++;
				s->dir.d = c;
			}
		}
		j = -1;
	}
	if (s->dir.x == 0)
	{
		s->pla.x = PLANEY;
		s->pla.y = PLANEX;
	}
}

/*******************************************
-function: parse sprite's lacation
-ar:	s 		->	structure(t_all)
-return: err number or 0
-call:	ft_free()
 *******************************************/
int		ft_slist(t_all *s)
{
	int	i;
	int	j;
	int	k;

	if (s->spr != NULL)
		s->spr = ft_free(s->spr);
	if (!(s->spr = malloc(sizeof(t_spr) * s->map.spr)))
		return (ERR);
	i = 0;
	j = 0;
	while (j < s->map.h)
	{
		k = 0;
		while (k < s->map.w)
		{
			if (s->map.tab[j][k] == '2')
			{
				s->spr[i].y = (double)j + 0.5;
				s->spr[i++].x = (double)k + 0.5;
			}
			k++;
		}
		j++;
	}	
	return (1);
}
