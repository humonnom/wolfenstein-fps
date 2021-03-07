#include "cub3d.h"
static 	void get_coef(t_plane plane, t_dir dir, t_pos pos, t_sprite *sprite)
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
	sprite->coef_x = (a * sprite->dist_x + b * sprite->dist_y);
	sprite->coef_y = (c * sprite->dist_x + d * sprite->dist_y);
}

static void	get_set(t_info *info, t_sprite *sprite)
{
	if (sprite->coef_x == 0)
		sprite->coef_x = 0.001;
	sprite->center_x = (int)((1 + sprite->coef_x / sprite->coef_y) * (info->win.x / 2));
	sprite->depth_unit = (fabs(sprite->coef_x)) / (fabs(sprite->coef_y));
	sprite->dist = (fabs(sprite->coef_x)) / sprite->depth_unit; 
	sprite->side_len = (int)((info->win.y / sprite->dist) / 2);
	sprite->draw_start = sprite->center_x - sprite->side_len / 2; 
	sprite->draw_end = sprite->center_x + sprite->side_len / 2;
	sprite->tex_scale = sprite->side_len / PIXEL_SIZE; 
	sprite->tex_step = 1.0 / sprite->tex_scale; 
//	sprite->tex_step = 1.0 * (PIXEL_SIZE / sprite->side_len); 
}

void	set_sprite(t_info *info)
{
	t_sprite	*tmp_spr;
	t_list		*cur;

	cur = info->sprite;
	while (cur)
	{
		tmp_spr = cur->content;
		get_coef(info->plane, info->dir, info->pos, tmp_spr);
		get_set(info, tmp_spr);
		cur = cur->next;
	}
}
//	sray = coef.x + coef.y
//	sray / coef.y = coef.x / coef.y + 1
