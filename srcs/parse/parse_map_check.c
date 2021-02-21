#include "cub3d.h"

static int	check_open(char **map, int step_line, int step_side)
{
	int	ret;
	int col;
	int	row;

	col = 0;
	row = 0;
	while (map[col][row] == '0')
		row++;


	return (ret);
}

int			parse_map_check(t_info *info)
{
	int ret;
	int i;

	ret = 0;
	i = -1;

	ret = check_open(info->map.tab, 0, 1);

//	while (info->map.tab[++i])
//		ps(info->map.tab[i]);
	return (ret);
}
