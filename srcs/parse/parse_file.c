#include "cub3d.h"

static int		parse_line(t_all *s, char *line)
{
	int	 i;
	
	i = 0;
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || s->err.m == 1) && line[i] != '\0')
		s->err.n = parse_map(s, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		s->err.n = parse_resolution(s, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = parse_texture(s, &s->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = parse_texture(s, &s->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		s->err.n = parse_texture(s, &s->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		s->err.n = parse_texture(s, &s->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		s->err.n = parse_texture(s, &s->tex.i, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		s->err.n = parse_colors(&s->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		s->err.n = parse_colors(&s->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && s->err.n == 0 && line[i] != '\0')
		return (err_filter(LINE_INV));
	return (s->err.n < 0 ? err_filter(s->err.n) : 0);		
}

int		parse_file(t_all *s, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == ERR)
		return (err_filter(FILE_OPEN));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (parse_line(s, line) == ERR)
			ret = ERR;
		free(line);
	}
	close(fd);
	if (ret == ERR || ret == -3)
		return (err_filter(FILE_PARSE));
	parse_pos(s);
	s->sprite = NULL;
	parse_sprite(s);
	return (parse_check(s));
}
