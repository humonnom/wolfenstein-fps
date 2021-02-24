#include "cub3d.h"

int	parse_file_post(t_info *info, int map_empty_flag)	
{
	int ret;

	ret = 0;
	if (map_empty_flag > 2 || arrange_map(info->map.w, info->map.tab))
		ret = 1;
	if (ret == 0)
	{
		parse_pos(info);
		parse_plane(info);
		info->sprite = NULL;
		parse_sprite(info);
	}
	return (ret);
}
