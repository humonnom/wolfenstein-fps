/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:42:32 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:42:34 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	handle_move(t_info *info, int c)
{
	int x;
	int y;

	x = info->pos.x + info->dir.x * info->time.ms * c;
	y = info->pos.y + info->dir.y * info->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < info->map.w && y < info->map.h &&\
		info->map.tab[y][x] != '1' &&\
		info->map.tab[y][x] != '2')
	{
		info->pos.x += info->dir.x * info->time.ms * c;
		info->pos.y += info->dir.y * info->time.ms * c;
	}
}

static void	handle_rotate(t_info *info, double c)
{
	double olddir;
	double oldplane;
	double rotspeed;

	rotspeed = info->time.rs * c;
	olddir = info->dir.x;
	info->dir.x = info->dir.x * cos(rotspeed) - info->dir.y * \
					sin(rotspeed);
	info->dir.y = olddir * sin(rotspeed) + info->dir.y * \
					cos(rotspeed);
	oldplane = info->plane.x;
	info->plane.x = info->plane.x * cos(rotspeed) - \
					info->plane.y * sin(rotspeed);
	info->plane.y = oldplane * sin(rotspeed) + info->plane.y * \
					cos(rotspeed);
}

static void	handle_strafe(t_info *info, int c)
{
	int x;
	int y;

	x = info->pos.x + info->dir.y * info->time.ms * -c;
	y = info->pos.y + info->dir.x * info->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < info->map.w && y < info->map.h &&\
		info->map.tab[y][x] != '1' &&\
		info->map.tab[y][x] != '2')
	{
		info->pos.x += info->dir.y * info->time.ms * -c;
		info->pos.y += info->dir.x * info->time.ms * c;
	}
}

int			get_key(int key, t_info *info)
{
	if (key == ESC)
		exit_game(info, 1);
	else if (key == W)
		handle_move(info, 1);
	else if (key == S)
		handle_move(info, -1);
	else if (key == A)
		handle_strafe(info, 1);
	else if (key == D)
		handle_strafe(info, -1);
	else if (key == LEFT)
		handle_rotate(info, 1);
	else if (key == RIGHT)
		handle_rotate(info, -1);
	draw_view(info, PRINT);
	return (0);
}
