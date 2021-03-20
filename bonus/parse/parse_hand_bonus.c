/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hand_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:42 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:43:43 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	parse_hand(t_info *info)
{
	int				ret;
	int				i;

	i = 0;
	ret = parse_texture(info, &(info->tex.h), "HD textures/hand.xpm", &i);
	if (ret)
		info->tex.h = 0;
}
