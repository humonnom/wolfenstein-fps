/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_col.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:54 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:16:54 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_init(t_info *i, int x)
{
	double	tmpx;
	double	tmpy;

	i->map.x = i->pos.x;
	i->map.y = i->pos.y;
	i->hit.f = 0;
	i->hit.s = 0;
	i->camera.x = 2 * x / (double)(i->win.x) - 1;
	i->ray.x = i->dir.x + i->plane.x * i->camera.x;
	i->ray.y = i->dir.y + i->plane.y * i->camera.x;
	tmpx = (sqrt(1 + (i->ray.y * i->ray.y) / (i->ray.x * i->ray.x)));
	tmpy = (sqrt(1 + (i->ray.x * i->ray.x) / (i->ray.y * i->ray.y)));
	if (i->ray.y == 0)
		i->dist.dx = 0;
	else if (i->ray.x == 0)
		i->dist.dx = 1;
	else
		i->dist.dx = tmpx;
	if (i->ray.x == 0)
		i->dist.dy = 0;
	else if (i->ray.x == 0)
		i->dist.dy = 1;
	else
		i->dist.dy = tmpy;
}

static void	set_step(t_info *info)
{
	if (info->ray.x < 0)
	{
		info->step.x = -1;
		info->dist.sx = (info->pos.x - info->map.x) * info->dist.dx;
	}
	else
	{
		info->step.x = 1;
		info->dist.sx = (info->map.x + 1.0 - info->pos.x) * info->dist.dx;
	}
	if (info->ray.y < 0)
	{
		info->step.y = -1;
		info->dist.sy = (info->pos.y - info->map.y) * info->dist.dy;
	}
	else
	{
		info->step.y = 1;
		info->dist.sy = (info->map.y + 1.0 - info->pos.y) * info->dist.dy;
	}
}

static void	set_dda(t_info *info)
{
	while (info->hit.f == 0)
	{
		if (info->dist.sx < info->dist.sy)
		{
			info->dist.sx += info->dist.dx;
			info->map.x += info->step.x;
			info->hit.s = 0;
		}
		else
		{
			info->dist.sy += info->dist.dy;
			info->map.y += info->step.y;
			info->hit.s = 1;
		}
		if (info->map.tab[info->map.y][info->map.x] == '1')
			info->hit.f = 1;
		if (info->map.tab[info->map.y][info->map.x] == '2')
			turn_on_spr_flag(info->map.x, info->map.y, info->sprite);
	}
}

static void	set_range(t_info *info)
{
	if (info->hit.s == 0)
	{
		info->dist.pw = (info->map.x - info->pos.x + (1 - info->step.x) / 2);
		info->dist.pw /= info->ray.x;
	}
	else
	{
		info->dist.pw = (info->map.y - info->pos.y + (1 - info->step.y) / 2);
		info->dist.pw /= info->ray.y;
	}
	info->screen.lh = (int)(info->win.y / info->dist.pw);
	info->screen.ds = -(info->screen.lh) / 2 + info->win.y / 2;
	if (info->screen.ds < 0)
		info->screen.ds = 0;
	info->screen.de = info->screen.lh / 2 + info->win.y / 2;
	if (info->screen.de >= info->win.y)
		info->screen.de = info->win.y - 1;
}

void		draw_window_col(t_info *info, int x)
{
	set_init(info, x);
	set_step(info);
	set_dda(info);
	set_range(info);
	set_wall(info, x);
	info->zbuf[x] = info->dist.pw;
}
