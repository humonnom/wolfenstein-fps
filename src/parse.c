#include "cub3d.h"

/*******************************************
-function: line handling 
-ar:	s 		->	structure(t_all)
		line	->	each line of map
-return: err number or 0
-call:	ft_map()
 		ft_res()
 		ft_texture()
 		ft_colors()
 		ft_strerr()
 *******************************************/
int		ft_line(t_all *s, char *line)
{
	int	 i;
	
	i = 0;
	ft_spaceskip(line, &i);
	if ((line[i] == '1' || s->err.m == 1) && line[i] != '\0')
		s->err.n = ft_map(s, line, &i);
	else if (line[i] == 'R' && line[i + 1] == ' ')
		s->err.n = ft_res(s, line, &i);
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.n, line, &i);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.s, line, &i);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.w, line, &i);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		s->err.n = ft_texture(s, &s->tex.e, line, &i);
	else if (line[i] == 'S' && line[i + 1] == ' ')
		s->err.n = ft_texture(s, &s->tex.i, line, &i);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		s->err.n = ft_colors(&s->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		s->err.n = ft_colors(&s->tex.c, line, &i);
	if (ft_spaceskip(line, &i) && s->err.n == 0 && line[i] != '\0')
		return (ft_strerr(LINE_INV));
	return (s->err.n < 0 ? ft_strerr(s->err.n) : 0);		
}

/*******************************************
-function: parsing 
-ar:	s 		->	structure(t_all)
		cub		->	map???
-return: ??? 
-call:	ft_pos()
		ft_line()
		ft_slist()
		ft_strerr()
		ft_parcheck()
 *******************************************/
int		ft_parse(t_all *s, char *cub)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(cub, O_RDONLY);
	if (fd == ERR)
		return (ft_strerr(FILE_OPEN));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ft_line(s, line) == ERR)
			ret = ERR;
		free(line);
	}
	close(fd);
	if (ret == ERR || ret == -3)
		return (ft_strerr(FILE_PARSE));
	ft_pos(s);
	s->spr = NULL;
	ft_slist(s);
	return (ft_parcheck(s));
}
