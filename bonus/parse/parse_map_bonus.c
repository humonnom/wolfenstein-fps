/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:49 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:43:49 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	get_space_flag(t_info *info, char *line)
{
	unsigned long	even;
	unsigned long	odd;
	int				i;

	even = 0;
	odd = 0;
	i = -1;
	info->map.space = -1;
	while (line[++i])
	{
		if (!(i % 2) && line[i] == ' ')
			even++;
		if ((i % 2) && line[i] == ' ')
			odd++;
	}
	if (ft_strlen(line) / 2 <= even + 1)
		info->map.space = 0;
	if (ft_strlen(line) / 2 <= odd + 1)
		info->map.space = 1;
}

int			parse_map(t_info *info, char *line)
{
	char	**buf;
	int		j;

	if (info->map.space == -2)
		get_space_flag(info, line);
	info->err.m = 1;
	if (!(buf = malloc(sizeof(char *) * (info->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	j = info->map.h + 1;
	while (--j > 0)
		buf[j] = info->map.tab[j - 1];
	if ((buf[0] = parse_map_part(info, line)) == NULL)
	{
		ft_2strfree(buf);
		return (MAP_INV);
	}
	buf[info->map.h + 1] = NULL;
	if (info->map.h > 0)
		free(info->map.tab);
	info->map.tab = buf;
	info->map.h++;
	info->map.w = ft_max(info->map.w, ft_strlen(info->map.tab[0]));
	return (info->err.n);
}
