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

static int		parse_line_else(t_info *info, char *line)
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
		ret  = parse_colors(&info->tex.f, line, &i);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		ret = parse_colors(&info->tex.c, line, &i);
	if (line[i])
		ret = LINE_INV;
	return (ret);
}
static int		parse_line_map(t_info *info, char *line, int *map_flag)
{
	int	ret;

	ret = 0;
	//ps("parse_line_map48\n");
	//pd(ret);
	*map_flag += handle_map_flag(line[0], *map_flag);
	//ps("parse_line_map51\n");
	//pd(ret);
	if (ret == 0)
		ret = parse_map(info, line);
	//ps("parse_line_map54\n");
	//pd(ret);
//	printf("line[i] : %c\n", line[i]);
//	pd(i);
//	printf("[[[parse_line_map]]] return :%d\n", pd(ret));
	return (ret);
}

static int		parse_line(t_info *info, char *line, int *map_flag)
{
	int	ret;

	ret = 0;
	if (*map_flag && line[0] == '\0')
	{
		(*map_flag)++;
		//ps("parse_line 69\n");
		//pd(ret);
	}
	else if (ret == 0 && ft_strchr("NSWESFCR", line[0]))
	{
		ret = parse_line_else(info, line);
		//ps("parse_line 75\n");
		//pd(ret);
	}
	else if (ret == 0 && ft_strchr("1 ", line[0]))
	{
		ret = parse_line_map(info, line, map_flag);
		//ps("parse_line 80\n");
		//pd(ret);
	}
	else
	{
		ret = LINE_INV;
		//ps("parse_line 93\n");
		//pd(ret);
	}
//	printf("[[[parse_line]]] return :%d\n", ret);
	if (ret == 0 && (*map_flag) > 2)
		ret = LINE_INV;
	info->err.n = ret; 
	return (ret);
}

int		parse_file(t_info *info, char *cub)
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
		//ps("get_next_line\n");
		//ps(line);
		ret = parse_line(info, line, &map_flag);
		free(line);
	}
	close(fd);
//	pd(ret);
//	ps("parse done\n");
//	int i = -1;
//	while (info->map.tab[++i])
//		ps(info->map.tab[i]);
//	if (ret == 0 && parse_file_post(info, map_flag) != 0)
//		ret = MAP_INV;
//	return (parse_check(info));
	return (ret);
}
