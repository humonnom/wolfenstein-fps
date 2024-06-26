/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:43:32 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:43:32 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	handle_map_flag(char c, int map_flag)
{
	int ret;

	ret = 0;
	if (c == '1' && map_flag == 0)
		ret = 1;
	if (c == '\0' && map_flag)
		ret = 1;
	return (ret);
}

static int	parse_line_else(t_info *info, char *line)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = parse_texture(info, &info->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		ret = parse_texture(info, &info->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		ret = parse_texture(info, &info->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		ret = parse_texture(info, &info->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		ret = parse_texture(info, &info->tex.i, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		ret = parse_resolution(info, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		ret = parse_colors(&info->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ret = parse_colors(&info->tex.c, line, &i);
	if (line[i])
		ret = LINE_INV;
	return (ret);
}

static int	parse_line_map(t_info *info, char *line, int *map_flag)
{
	int	ret;

	ret = 0;
	*map_flag += handle_map_flag(line[0], *map_flag);
	if (ret == 0)
		ret = parse_map(info, line);
	return (ret);
}

static int	parse_line(t_info *info, char *line, int *map_flag)
{
	int	ret;

	ret = 0;
	if (*map_flag && line[0] == '\0')
		(*map_flag)++;
	else if (ret == 0 && ft_strchr("NSWESFCR", line[0]))
		ret = parse_line_else(info, line);
	else if (ret == 0 && ft_strchr("1 ", line[0]))
		ret = parse_line_map(info, line, map_flag);
	else
		ret = LINE_INV;
	if ((*map_flag) > 2)
		ret = LINE_INV;
	info->err.n = ret;
	return (ret);
}

int			parse_file(t_info *info, char *cub)
{
	char	*line;
	int		fd;
	int		read;
	int		map_flag;
	int		ret;

	ret = 0;
	map_flag = 0;
	if ((fd = open(cub, O_RDONLY)) == -1)
		ret = FILE_OPEN;
	read = 1;
	while (ret == 0 && read > 0)
	{
		read = (get_next_line(fd, &line));
		ret = parse_line(info, line, &map_flag);
		free(line);
	}
	parse_hand(info);
	close(fd);
	if (ret == 0 && parse_file_post(info) != 0)
		ret = MAP_INV;
	if (ret)
		return (ret);
	return (parse_check(info));
}
