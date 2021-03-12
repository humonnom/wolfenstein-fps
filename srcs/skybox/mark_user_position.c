/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_user_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:42:33 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:42:34 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			mark_user_position(t_info *info, const t_mini *m)
{
	int user_pos;
	int ret;

	user_pos = get_position(info->pos, m->bsize, info->win.x, info->map.h);
	ret = !(user_pos);
	if (ret == 0)
		draw_rect(info, user_pos, BLUE, 6);
	if (ret == 0)
		return (user_pos);
	return (ret);
}
