/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:33:43 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 16:35:41 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	*renew_map_line(char *old, int width)
{
	char	*new;
	char	*tmp;
	char	*space;
	int		space_num;
	int		ret;

	ret = 0;
	new = NULL;
	space_num = width - ft_strlen(old);
	if (!(space = ft_strdup("")))
		ret = 1;
	tmp = NULL;
	while (ret == 0 && space_num--)
	{
		tmp = space;
		if (!(space = ft_strjoin(tmp, " ")))
			ret = 1;
		free(tmp);
	}
	if (ret == 0 && !(new = ft_strjoin(old, space)))
		ret = 1;
	if (ret == 0)
		free(old);
	return (new);
}

int			arrange_map(int max_width, char **map)
{
	int i;
	int ret;

	ret = 0;
	i = -1;
	while (map[++i] && ret == 0)
	{
		if ((int)ft_strlen(map[i]) < max_width)
			if (!(map[i] = renew_map_line(map[i], max_width)))
				ret = 1;
	}
	return (ret);
}
