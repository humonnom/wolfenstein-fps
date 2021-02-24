#include "cub3d.h"

int	parse_map_check(t_info *info)
{
	int ret;
	int i;
	char **map;

	ret = 0;
	i = -1;
	map = info->map.tab;
	i = map_check_open(map);
	return (ret);
}
