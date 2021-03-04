#include "cub3d.h"
#if 0

void	turn_on_sprite_flag(int x, int y, t_list *sprite)
{
	t_sprite *cur;

	cur = sprite->data;
	while (cur)
	{
		if ((cur->visible == 0) && x == cur->x && y == cur->y)
			cur->visible = 1;
		cur = cur->next;
	}
}
#endif
