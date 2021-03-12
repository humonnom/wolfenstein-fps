/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:11 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:16:13 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	draw_sprite(t_info *info, t_sprite *sprite)
{
	int x;
	int spr_x;

	x = -1;
	while (++x < info->win.x)
	{
		if (x >= sprite->draw_start && x <= sprite->draw_end)
		{
			spr_x = x - sprite->draw_start;
			if (info->zbuf[x] > sprite->dist && spr_x >= 0)
				draw_sprite_col(info, sprite, x, spr_x);
		}
	}
	return (0);
}
