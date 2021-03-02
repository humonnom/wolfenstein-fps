#include "cub3d.h"
#if 1
static 	void get_sprite_distance(t_plane plane, t_dir dir, t_pos pos, t_sprite *sprite)
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	devider;

	sprite->dist_x = sprite->x - pos.x;
	sprite->dist_y = sprite->y - pos.y;
	devider = (plane.x * dir.y) - (dir.x * plane.y);
	a = dir.y / devider;
	b = -(dir.x) / devider;
	c = -(plane.y) / devider;
	d = plane.x / devider;
	sprite->coef_x = (a * sprite->dist_x) + (b * sprite->dist_y);
	sprite->coef_y = (c * sprite->dist_x) + (d * sprite->dist_y);
}

#endif
void	draw_sprite_meta(t_info *info)
{
	t_sprite	*sprite;
	t_list		*cur;
	int			ret;

	ret = 0;
	cur = info->sprite;
	while (cur && ret == 0)
	{
		sprite = cur->content;
		get_sprite_distance(info->plane, info->dir, info->pos, sprite);
		cur = cur->next;
		ret = 1;
	}
	cur = info->sprite;
	sprite = cur->content;
	//arrange_order(sprite);
	//draw all sprite using while();
	draw_sprite(info, sprite);
//	ret = 0;
//	cur = info->sprite;
//	while (cur && ret == 0)
//	{
//		sprite = cur->content;
//		printf("sprite coef_x:%f\n", sprite->coef_x);
//		printf("sprite coef_y:%f\n", sprite->coef_y);
//		cur = cur->next;
//	}
}
