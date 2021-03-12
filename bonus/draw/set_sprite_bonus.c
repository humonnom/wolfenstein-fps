/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:42:07 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:42:08 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_coef(
			t_plane plane,
			t_dir dir,
			t_pos pos,
			t_sprite *sprite)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	devider;

	sprite->dist_x = sprite->x - pos.x;
	sprite->dist_y = sprite->y - pos.y;
	devider = (plane.x * dir.y) - (dir.x * plane.y);
	a = dir.y / devider;
	b = -(dir.x) / devider;
	c = -(plane.y) / devider;
	d = plane.x / devider;
	sprite->coef_x = (a * sprite->dist_x + b * sprite->dist_y);
	sprite->coef_y = (c * sprite->dist_x + d * sprite->dist_y);
}

void		get_set(t_info *info, t_sprite *spr)
{
	if (spr->coef_x == 0)
		spr->coef_x = 0.001;
	spr->center_x = \
	(int)((1 + spr->coef_x / spr->coef_y) * (info->win.x / 2));
	spr->depth_unit = (fabs(spr->coef_x)) / (fabs(spr->coef_y));
	spr->dist = (fabs(spr->coef_x)) / spr->depth_unit;
	spr->side_len = (int)((info->win.y / spr->dist) / 2) * 2;
	spr->draw_start = spr->center_x - spr->side_len / 2;
	spr->draw_end = spr->center_x + spr->side_len / 2;
	spr->tex_scale = spr->side_len / PIXEL_SIZE;
	spr->tex_step = 1.0 / spr->tex_scale;
}

void		set_sprite(t_info *info)
{
	t_sprite	*tmp_spr;
	t_list		*cur;

	cur = info->sprite;
	while (cur)
	{
		tmp_spr = cur->content;
		get_coef(info->plane, info->dir, info->pos, tmp_spr);
		get_set(info, tmp_spr);
		cur = cur->next;
	}
}
