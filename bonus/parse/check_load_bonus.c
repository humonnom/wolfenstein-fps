/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:08:57 by jackjoo           #+#    #+#             */
/*   Updated: 2021/03/21 01:31:02 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_eof_range(int i, int j, int max[])
{
	int ret;

	ret = 0;
	if (i == max[0])
		ret++;
	else if (i == 0)
		ret++;
	else if (j == max[1])
		ret++;
	else if (j == 0)
		ret++;
	return (ret);
}

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

int	check_empty(char **map, int i, int j, int max[])
{
	int flag;
	int step;

	flag = 0;
	step = max[2];
	if (is_valid_range(i + step, j, max) && \
		map[i + step] && map[i + step][j] == ' ')
		flag++;
	if (is_valid_range(i, j + step, max) && \
		map[i] && map[i][j + step] == ' ')
		flag++;
	step *= -1;
	if (is_valid_range(i + step, j, max) && \
		map[i + step] && map[i + step][j] == ' ')
		flag++;
	if (is_valid_range(i, j + step, max) && \
		map[i] && map[i][j + step] == ' ')
		flag++;
	if (is_eof_range(i, j, max))
		flag++;
	return (flag);
}
