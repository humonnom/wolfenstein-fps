/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:44:29 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:44:30 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		mark_direction(t_info *info, const t_mini *m, int pos)
{
	double	x;
	double	y;
	double	len;
	int		dir;
	int		i;

	x = info->dir.x * m->bsize;
	y = info->dir.y * m->bsize;
	len = (fabs(y) == 0) ? fabs(x) : fabs(y);
	i = 0;
	while (i++ < len)
	{
		dir = ((x * i / len) - ((y * i / len) * info->win.x)) + pos;
		if (dir > 0 && dir < (info->win.x * m->h) \
			&& (dir % info->win.x) > (pos % info->win.x - m->bsize) \
			&& (dir % info->win.x) < (pos % info->win.x + m->bsize))
			info->img.adr[dir] = DARK_BLUE;
	}
}
