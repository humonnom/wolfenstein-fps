#include "cub3d.h"

static int		handle_map_flag(char c, int map_flag)
{
	int ret;

	ret = 0;
	if (c == '1' && map_flag == 0)
		ret = 1;
	if (c == '\0' && map_flag)
		ret = 1;
	return (ret);
}

static int		parse_line_texture(t_info *info, char *line, int *index)
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
	*index = i;
	return (ret);
}

static int		parse_line(t_info *info, char *line, int *map_flag)
{
	int	 i;
	
	i = 0;
	*map_flag += handle_map_flag(line[i], *map_flag);
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || line[i] == ' ' || info->err.m == 1) && line[i] != '\0')
		info->err.n = parse_map(info, line, &i);
	else if (ft_strchr("NSWE", line[i]))
		info->err.n = parse_line_texture(info, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		info->err.n = parse_resolution(info, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		info->err.n = parse_colors(&info->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		info->err.n = parse_colors(&info->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && info->err.n == 0 && line[i] != '\0')
		info->err.n = LINE_INV;
	return (info->err.n < 0 ? report_err(info->err.n) : 0);		
}

int		parse_file(t_info *info, char *cub)
{
	char	*line;
	int		fd;
	int		read;
	int		map_flag;
	
	map_flag = 0;
	if ((fd = open(cub, O_RDONLY)) == ERR)
		return (report_err(FILE_OPEN));
	read = 1;
	while (read > 0)
	{
		read = (get_next_line(fd, &line));
		if (parse_line(info, line, &map_flag))
			return (report_err(FILE_PARSE));
		free(line);
	}
	close(fd);
	if (parse_file_post(info, map_flag) != 0)
		return (report_err(MAP_INV));
	return (parse_check(info));
}
