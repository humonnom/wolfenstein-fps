/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_load_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:37:06 by jackjoo           #+#    #+#             */
/*   Updated: 2021/03/20 11:37:08 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_valid_range(int i, int j, int max[])
{
	int ret;

	ret = 0;
	if (i >= max[0])
		ret++;
	if (i < 0)
		ret++;
	if (j >= max[1])
		ret++;
	if (j < 0)
		ret++;
	return (!ret);
}

int	check_load(char **map, int i, int j, int max[])
{
	int count;
	int step;

	count = 0;
	step = max[2];
	if (is_valid_range(i + step, j, max) && \
			map[i + step] && map[i + step][j] == '1')
		count++;
	if (is_valid_range(i, j + step, max) && \
			map[i] && map[i][j + step] == '1')
		count++;
	step *= -1;
	if (is_valid_range(i + step, j, max) && \
			map[i + step] && map[i + step][j] == '1')
		count++;
	if (is_valid_range(i, j + step, max) && \
			map[i] && map[i][j + step] == '1')
		count++;
	return (count);
}
