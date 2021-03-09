#include "cub3d.h"
static void	sort_sprite(t_list *sprite)
{
	t_sprite	*spr1;
	t_sprite	*spr2;
	t_list		*begin;
	t_list		*cur;

	begin = sprite;
	while (begin->next)
	{
		cur = begin;
		while (cur->next)
		{
			spr1 = cur->content;
			spr2 = cur->next->content;
			if (spr1->dist < spr2->dist)
			{
				cur->content = spr2;
				cur->next->content = spr1;
			}
			cur = cur->next;
		}
		begin = begin->next;
	}
}

void	draw_sprite_meta(t_info *info)
{
	t_sprite	*tmp_spr;
	t_list		*cur;

	set_sprite(info);
	sort_sprite(info->sprite);
	cur = info->sprite;
	while (cur)
	{
		tmp_spr = cur->content;
		if (tmp_spr->visible)
		{
			draw_sprite(info, tmp_spr);
			tmp_spr->visible = 0;
		}
		cur = cur->next;
	}
}
