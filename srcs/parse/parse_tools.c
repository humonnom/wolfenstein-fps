/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:45:13 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:45:14 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_resolution(t_info *info, char *line, int *i)
{
	if (info->win.x != 0 || info->win.y != 0)
		return (RES_DOUBLE);
	(*i)++;
	info->win.x = ft_atoiskip(line, i);
	info->win.y = ft_atoiskip(line, i);
	if (info->win.x > 2560)
		info->win.x = 2560;
	if (info->win.y > 1400)
		info->win.y = 1400;
	ft_spaceskip(line, i);
	if (info->win.x <= 0 || info->win.y <= 0 || line[*i] != '\0')
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

void	parse_plane(t_info *info)
{
	if (info->dir.x == 0)
	{
		info->plane.x = PLANEY;
		info->plane.y = PLANEX;
	}
	info->plane.x *= (info->dir.d == 'S') ? -1 : 1;
	info->plane.y *= (info->dir.d == 'E') ? -1 : 1;
}

void	parse_pos(t_info *info)
{
	char	c;
	int		i;
	int		j;

	i = -1;
	while (++i < info->map.h)
	{
		j = -1;
		while (++j < info->map.w)
		{
			c = info->map.tab[i][j];
			if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
			{
				info->pos.y = (double)i + 0.5;
				info->pos.x = (double)j + 0.5;
				info->dir.x = (c == 'E' || c == 'W') ? 1 : 0;
				info->dir.x *= (c == 'W') ? -1 : 1;
				info->dir.y = (c == 'S' || c == 'N') ? 1 : 0;
				info->dir.y *= (c == 'S') ? -1 : 1;
				info->err.p++;
				info->dir.d = c;
			}
		}
	}
}
