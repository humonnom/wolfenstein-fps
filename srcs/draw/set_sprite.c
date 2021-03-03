#include "cub3d.h"
void	set_sprite(t_info *info, t_sprite *sprite)
{
	sprite->center = sprite->coef_x * (info->win.x / 2);
	sprite->depth_unit = (fabs(sprite->coef_x)) / (fabs(sprite->coef_y));
	sprite->dist = (fabs(sprite->coef_x)) / sprite->depth_unit; 
	sprite->side_len = (int)(info->win.y / sprite->dist);
	sprite->draw_start = sprite->center - sprite->side_len / 2; 
	if (sprite->draw_start < 0)
		sprite->draw_start = 0;
	sprite->draw_end = sprite->center + sprite->side_len / 2;
	if (sprite->draw_end > info->win.y)
		sprite->draw_end = info->win.y;
}
