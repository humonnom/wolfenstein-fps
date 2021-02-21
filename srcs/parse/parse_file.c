#include "cub3d.h"

static int		parse_line(t_info *info, char *line)
{
	int	 i;
	
	i = 0;
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || line[i] == ' ' || info->err.m == 1) && line[i] != '\0')
		info->err.n = parse_map(info, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		info->err.n = parse_resolution(info, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		info->err.n = parse_texture(info, &info->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		info->err.n = parse_texture(info, &info->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		info->err.n = parse_texture(info, &info->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		info->err.n = parse_texture(info, &info->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		info->err.n = parse_texture(info, &info->tex.i, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		info->err.n = parse_colors(&info->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		info->err.n = parse_colors(&info->tex.c, line, &i);
	else if (ft_spaceskip(line, &i) && info->err.n == 0 && line[i] != '\0')
	{
		ps("here?\n");
		info->err.n = LINE_INV;
	}
	return (info->err.n < 0 ? report_err(info->err.n) : 0);		
}

int		parse_file(t_info *info, char *cub)
{
	char	*line;
	int		fd;
	int		read;
	
	if ((fd = open(cub, O_RDONLY)) == ERR)
		return (report_err(FILE_OPEN));
	read = 1;
	while (read > 0)
	{
		read = (get_next_line(fd, &line));
		if (parse_line(info, line))
			return (FILE_PARSE);
		free(line);
	}
	close(fd);
	if (arrange_map(info->map.w, info->map.tab))
		return (FILE_PARSE);
	parse_pos(info);
	parse_plane(info);
	info->sprite = NULL;
	parse_sprite(info);
	return (parse_check(info));
}
