/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:44:28 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:44:29 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		get_part_len(t_info *info, char *line)
{
	int	i;
	int count;

	i = -1;
	count = 0;
	while (line[++i])
	{
		if (ft_strchr("0123NSWE", line[i]))
			count++;
	}
	if (info->map.w < count)
		info->map.w = count;
	return (count);
}
