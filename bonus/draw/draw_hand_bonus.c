/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:03 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:16:04 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_hand_col(
			t_info *info,
			t_sprite *hand,
			int x,
			int xpm_x)
{
	int	pixel;
	int	dot;
	int	center;
	int	xpm_y;
	int	y;

	center = info->win.y - hand->side_len / 2;
	y = (center - hand->side_len / 2) - 1;
	if (y < 0)
		y = -1;
	xpm_y = -1;
	while (++y < center + hand->side_len / 2)
	{
		++xpm_y;
		dot = (int)(x + info->win.x * y);
		pixel = (int)(xpm_x * hand->tex_step) + \
				(int)(xpm_y * hand->tex_step) * PIXEL_SIZE;
		if (x < info->win.x && y < info->win.y && \
				pixel < pow(PIXEL_SIZE, 2))
		{
			if (info->tex.h[pixel] != NONE)
				info->img.adr[dot] = info->tex.h[pixel];
		}
	}
}

void		draw_hand(t_info *info)
{
	int				i;
	int				x;
	t_sprite		*hand;

	i = 0;
	if (info->tex.h == 0)
		return ;
	if (!(hand = get_content(0, 0)))
		return ;
	hand->coef_x = 0;
	hand->coef_y = 2;
	get_set(info, hand);
	x = hand->draw_start - 1;
	while (++x < hand->draw_end)
	{
		if (x >= 0 && x < info->win.x)
			draw_hand_col(info, hand, x, x - hand->draw_start);
	}
	free(hand);
}
