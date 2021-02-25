#include "cub3d.h"

int	parse_map_check(t_info *info)
{
	int ret;

	ret = 0;
	ret = map_check_open(info->map.tab);
	return (ret);
}
