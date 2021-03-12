/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_on_spr_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:17:09 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:17:10 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	turn_on_spr_flag(int x, int y, t_list *spr_list)
{
	t_list		*cur;
	t_sprite	*spr;

	cur = spr_list;
	while (cur)
	{
		spr = (t_sprite *)cur->content;
		if ((x == (int)spr->x) && (y == (int)spr->y))
			spr->visible = 1;
		cur = cur->next;
	}
}
