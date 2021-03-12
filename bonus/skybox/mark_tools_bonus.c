/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:42:23 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:42:25 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		get_position(t_pos pos, int bsize, int win_x, int map_h)
{
	int position;

	position = (int)(pos.x * bsize) + \
			(int)((map_h - pos.y) * bsize) * win_x;
	return (position);
}

void	draw_rect(t_info *info, int pos, int color, int width)
{
	int pm;
	int	i;
	int	j;

	pm = width / 2;
	i = -pm;
	while (++i < pm)
	{
		j = -pm;
		while (++j < pm)
			info->img.adr[pos + j + (info->win.x * i)] = color;
	}
}
