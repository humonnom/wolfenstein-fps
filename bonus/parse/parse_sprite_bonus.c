/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:44:39 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:44:40 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_sprite	*get_content(double x, double y)
{
	t_sprite	*ret;

	ret = NULL;
	if ((ret = (t_sprite *)malloc(sizeof(t_sprite))))
	{
		ret->x = x;
		ret->y = y;
		ret->coef_x = 0;
		ret->coef_y = 0;
		ret->dist_x = 0;
		ret->dist_y = 0;
		ret->draw_start = 0;
		ret->draw_end = 0;
		ret->center_x = 0;
		ret->depth_unit = 0;
		ret->dist = 0;
		ret->side_len = 0;
		ret->visible = 0;
		ret->crushed = 0;
		ret->tex_scale = 0;
		ret->tex_step = 0;
	}
	return (ret);
}

int			parse_sprite(t_info *info)
{
	int			j;
	int			k;
	int			ret;
	t_sprite	*tmp_spr;

	ret = 0;
	if (info->sprite != NULL)
		ret = SPRITE_DOUBLE;
	j = -1;
	while (ret == 0 && ++j < info->map.h)
	{
		k = -1;
		while (ret == 0 && ++k < info->map.w)
		{
			if (info->map.tab[j][k] == '2')
			{
				if (!(tmp_spr = get_content(k + 0.5, j + 0.5)))
					ret = 1;
				ft_lstadd_back(&info->sprite, ft_lstnew(tmp_spr));
				info->map.sprite++;
			}
		}
	}
	return (ret);
}
