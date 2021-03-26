/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:09 by juepark           #+#    #+#             */
/*   Updated: 2021/03/26 21:41:36 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char		**map_check_pre(char **map, int *i, int *j)
{
	(*i) = 0;
	(*j) = 0;
	ft_spaceskip(map[0], j);
	if (map[0][(*j)] != '1')
		return (0);
	map[0][(*j)] = 'w';
	return (map);
}

static int		map_check_post(char **map, char **map_cpy, int max[])
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = -1;
	while (ret == 0 && map[++i])
	{
		j = -1;
		while (ret == 0 && map[i][++j])
			if (map[i][j] == '1' && map_cpy[i][j] != 'w')
			{
				if (check_empty(map, i, j, max))
					ret = MAP_INV;
			}
	}
	return (ret);
}

int				map_check(t_map *map)
{
	int		ret;
	char	**map_cpy;
	int		i;
	int		j;
	int		max[3];

	ret = 0;
	if (!(map_cpy = ft_2strdup(map->tab)))
		return (1);
	if (ret == 0)
	{
		map_cpy = map_check_pre(map_cpy, &i, &j);
		ret = !(map_cpy);
	}
	if (ret == 0)
	{
		max[0] = map->h;
		max[1] = map->w;
		max[2] = 1;
		map_check_iter(map_cpy, i, j, max);
		max[2] = 1;
		ret = map_check_post(map->tab, map_cpy, max);
	}
	ft_2strfree(map_cpy);
	return (ret);
}
