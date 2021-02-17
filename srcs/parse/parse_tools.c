#include "cub3d.h"

int		parse_resolution(t_all *s, char *line, int *i)
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

int		parse_colors(unsigned int *color, char *line, int *i)
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

void	parse_plane(t_all *s)
{
	if (s->dir.x == 0)
	{
		s->pla.x = PLANEY;
		s->pla.y = PLANEX;
	}
	s->pla.x *= (s->dir.d == 'S') ? -1 : 1;
	s->pla.y *= (s->dir.d == 'E') ? -1 : 1;
}

void	parse_pos(t_all *s)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < s->map.h)
	{
		j = -1;
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
				s->dir.y *= (c == 'S') ? -1 : 1;
				s->err.p++;
				s->dir.d = c;
			}
		}
	}
}

int		parse_sprite(t_all *s)
{
	int	i;
	int	j;
	int	k;

	if (s->sprite != NULL)
		s->sprite = ft_free(s->sprite);
	if (!(s->sprite = malloc(sizeof(t_sprite) * s->map.sprite)))
		return (ERR);
	i = 0;
	j = -1;
	while (++j < s->map.h)
	{
		k = -1;
		while (++k < s->map.w)
		{
			if (s->map.tab[j][k] == '2')
			{
				s->sprite[i].y = (double)j + 0.5;
				s->sprite[i++].x = (double)k + 0.5;
			}
		}
	}	
	return (DONE);
}
