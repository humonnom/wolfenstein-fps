/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:44:35 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:44:36 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		mark_objects(t_info *info, const t_mini *m)
{
	int user_pos;
	int ret;

	user_pos = mark_user_position(info, m);
	ret = !(user_pos);
	if (ret == 0)
		mark_direction(info, m, user_pos);
	if (ret == 0)
		ret = mark_sprite(info, m);
	if (ret)
		return (MARK_ERR);
	return (ret);
}
