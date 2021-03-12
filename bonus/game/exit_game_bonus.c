/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:31:46 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 22:31:49 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	clear_tex(t_info *info)
{
	info->tex.n = ft_free(info->tex.n);
	info->tex.s = ft_free(info->tex.s);
	info->tex.e = ft_free(info->tex.e);
	info->tex.w = ft_free(info->tex.w);
	info->tex.i = ft_free(info->tex.i);
	info->tex.h = ft_free(info->tex.h);
}

int			exit_game(t_info *info, int win)
{
	t_list	*cur;
	t_list	*tmp;

	if (info->map.tab)
		ft_2strfree(info->map.tab);
	clear_tex(info);
	if (win == 1)
		mlx_destroy_window(info->mlx.ptr, info->win.ptr);
	if (info->pid > 0)
		kill(info->pid + 1, SIGTERM);
	cur = info->sprite;
	while (cur)
	{
		tmp = cur->next;
		ft_lstdelone(cur, &free);
		cur = tmp;
	}
	info->zbuf = ft_free(info->zbuf);
	exit(0);
	return (1);
}
