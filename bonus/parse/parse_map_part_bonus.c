/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:44:06 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:44:07 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		get_parsed_len(
				const char *str,
				char c,
				int space_flag)
{
	int count;
	int i;

	count = 0;
	i = -1;
	if (space_flag < 0)
		count = ft_strlen(str);
	while (space_flag >= 0 && str[++i])
	{
		if (str[i] != c)
			count++;
	}
	return (count);
}

static char		*get_line_cpy(char *str, int space_flag, char subs)
{
	int		i;
	int		step;
	char	*str_cpy;

	if (!(str_cpy = ft_strdup(str)))
		return (NULL);
	i = space_flag;
	step = 2;
	while (space_flag >= 0 && str_cpy[i])
	{
		if (str_cpy[i] == ' ')
			str_cpy[i] = subs;
		i += step;
	}
	return (str_cpy);
}

static char		*get_parsed_map(
				char *parsed,
				char *line_cpy,
				char subs)
{
	int		index;
	int		j;

	j = -1;
	index = -1;
	while (line_cpy[++index])
	{
		if (ft_strchr("012NSWE ", line_cpy[index]))
			parsed[++j] = line_cpy[index];
		else if (line_cpy[index] != subs)
		{
			free(parsed);
			return (NULL);
		}
	}
	parsed[++j] = '\0';
	return (parsed);
}

char			*parse_map_part(t_info *info, char *line)
{
	char	*parsed;
	char	*line_cpy;
	int		parsed_len;
	char	subs;

	subs = '3';
	if (!(line_cpy = get_line_cpy(line, info->map.space, subs)))
		return (0);
	parsed_len = get_parsed_len(line_cpy, subs, info->map.space);
	if (!(parsed = malloc(sizeof(char) * (parsed_len + 1))))
		return (0);
	parsed = get_parsed_map(parsed, line_cpy, subs);
	ft_free(line_cpy);
	return (parsed);
}
