#include "cub3d.h"
void	turn_on_spr_flag(int x, int y, t_list *spr_list)
{
	t_list		*cur;
	t_sprite	*spr;

	cur = spr_list;
	while (cur)
	{
		spr = (t_sprite *)cur->content;
		if ((x == (int)spr->x) && (y == (int)spr->y))
			spr->visible = 1;
		cur = cur->next;
	}
}
