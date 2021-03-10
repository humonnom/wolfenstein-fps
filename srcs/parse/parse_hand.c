#include "cub3d.h"

void	parse_hand(t_info *info)
{
	int				ret;
	int				i;

	i = 0;
	ret = parse_texture(info, &(info->tex.h), "HD textures/hand.xpm", &i);
	if (ret)
		info->tex.h = 0;	
}
