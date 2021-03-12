/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:42:16 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:42:18 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	mark_sprite(t_info *info, const t_mini *m)
{
	t_list		*cur;
	t_sprite	*sprite;
	t_pos		pos;
	int			sprite_pos;

	cur = info->sprite;
	if (!cur)
		return (1);
	while (cur)
	{
		if (!(sprite = cur->content))
			break ;
		pos.x = sprite->x;
		pos.y = sprite->y;
		sprite_pos = get_position(pos, m->bsize, info->win.x, info->map.h);
		if (sprite_pos)
			draw_rect(info, sprite_pos, LIGHT_BLUE_GREY, 6);
		cur = cur->next;
	}
	return (0);
}
