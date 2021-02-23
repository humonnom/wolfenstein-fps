#include "cub3d.h"



static void	get_sprite_drawing_info(t_info *info)
{
	t_sprite	*sprite;
	t_list		*cur;
	int			ret;

	ret = 0;
	cur = info->sprite;
	while (cur && ret == 0)
	{
		sprite = cur->content;
		printf("=========\n");
		draw_sprite_col(info, sprite);
		pf(sprite->lh);
		cur = cur->next;
		ret = 1;
	}
}

void	draw_sprite(t_info *info)
{
	get_sprite_drawing_info(info);
}
