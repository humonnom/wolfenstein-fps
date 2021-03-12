/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:41:41 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:41:42 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprite(t_list *sprite)
{
	t_sprite	*spr1;
	t_sprite	*spr2;
	t_list		*begin;
	t_list		*cur;

	begin = sprite;
	while (begin->next)
	{
		cur = begin;
		while (cur->next)
		{
			spr1 = cur->content;
			spr2 = cur->next->content;
			if (spr1->dist < spr2->dist)
			{
				cur->content = spr2;
				cur->next->content = spr1;
			}
			cur = cur->next;
		}
		begin = begin->next;
	}
}

static int	handle_map_spr(char **map, t_sprite *spr)
{
	int changed;

	changed = 0;
	if (spr->crushed)
	{
		map[(int)spr->y][(int)spr->x] = 0;
		changed = 1;
	}
	return (changed);
}

static void	handle_crushed_sprite(char **map, t_list **head)
{
	t_list		*cur;
	t_list		*tmp;

	cur = *head;
	if (handle_map_spr(map, cur->content))
	{
		tmp = cur->next;
		ft_lstdelone(cur, &free);
		*head = tmp;
		return ;
	}
	while (cur->next)
	{
		if (handle_map_spr(map, cur->next->content))
		{
			tmp = cur->next->next;
			ft_lstdelone(cur->next, &free);
			cur->next = tmp;
			return ;
		}
		cur = cur->next;
	}
}

void		draw_sprite_meta(t_info *info)
{
	t_sprite	*tmp_spr;
	t_list		*cur;

	if (info->sprite == NULL)
		return ;
	set_sprite(info);
	sort_sprite(info->sprite);
	cur = info->sprite;
	while (cur)
	{
		tmp_spr = cur->content;
		if (tmp_spr->visible && !tmp_spr->crushed)
		{
			if ((fabs(tmp_spr->dist_x) <= 1) && \
				(fabs(tmp_spr->dist_y) <= 1))
				tmp_spr->crushed = 1;
			else
				draw_sprite(info, tmp_spr);
			tmp_spr->visible = 0;
		}
		cur = cur->next;
	}
	handle_crushed_sprite(info->map.tab, &(info->sprite));
}
