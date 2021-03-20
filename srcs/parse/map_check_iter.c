/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_iter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:19 by juepark           #+#    #+#             */
/*   Updated: 2021/03/20 11:23:42 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			get_tmp_max(int max[], int tmp[])
{
	tmp[0] = max[0];
	tmp[1] = max[1];
	tmp[2] = 1;
}

int					map_check_iter(char **map, int i, int j, int max[])
{
	int tmp[3];

	if ((check_load(map, i, j, max) == 0))
		return (1);
	else if (is_valid_range(i, j + max[2], max) && \
			map[i][j + max[2]] && map[i][j + max[2]] == '1')
	{
		j += max[2];
		map[i][j] = 'w';
	}
	else if (is_valid_range(i + max[2], j, max) && \
			map[i + max[2]] && map[i + max[2]][j] == '1')
	{
		i += max[2];
		map[i][j] = 'w';
	}
	else if (max[2] == 1)
	{
		max[2] = -1;
		return (map_check_iter(map, i, j, max));
	}
	get_tmp_max(max, tmp);
	if ((map_check_iter(map, i, j, tmp)) == 1)
		return (map_check_iter(map, i, j, max));
	return (0);
}
