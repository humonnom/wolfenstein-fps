/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:41:57 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:41:59 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_view(t_info *info)
{
	t_ray	ray;
	t_hit	hit;

	ray.x = 0;
	ray.y = 0;
	ray.i = 0;
	ray.v = 0;
	ray.w = 0;
	hit.f = 0;
	hit.s = 0;
	info->ray = ray;
	info->hit = hit;
}

void		draw_view(t_info *info, int print)
{
	int		tab[3];

	init_view(info);
	info->img.ptr = mlx_new_image(info->mlx.ptr, info->win.x, info->win.y);
	info->img.adr = (unsigned int *)mlx_get_data_addr(info->img.ptr,\
			&tab[0], &tab[1], &tab[2]);
	draw_background(info);
	draw_window(info);
	draw_sprite_meta(info);
	draw_minimap(info);
	draw_hand(info);
	if (print)
		mlx_put_image_to_window(info->mlx.ptr, \
					info->win.ptr, info->img.ptr, 0, 0);
	free(info->img.ptr);
	free(info->img.adr);
}
