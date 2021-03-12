/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_post.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:37 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:43:38 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file_post(t_info *info)
{
	int ret;

	ret = 0;
	if (arrange_map(info->map.w, info->map.tab))
		ret = 1;
	if (ret == 0)
	{
		parse_pos(info);
		parse_plane(info);
		info->sprite = NULL;
		parse_sprite(info);
	}
	return (ret);
}
