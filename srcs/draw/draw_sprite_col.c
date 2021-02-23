#include "cub3d.h"

static void	set_init(t_info *info, int x)
{
	double	tmpx;
	double	tmpy;

	info->map.x = info->pos.x;
	info->map.y = info->pos.y;
	info->hit.f = 0;
	info->hit.s = 0;
	info->camera.x = 2 * x / (double)(info->win.x) - 1;
	info->ray.x = info->dir.x + info->plane.x * info->camera.x;
	info->ray.y = info->dir.y + info->plane.y * info->camera.x;
	tmpx = (sqrt(1 + (info->ray.y * info->ray.y) / (info->ray.x * info->ray.x)));
	tmpy = (sqrt(1 + (info->ray.x * info->ray.x) / (info->ray.y * info->ray.y)));
	info->dist.dx = (info->ray.y == 0) ? 0 : ((info->ray.x == 0) ? 1 : tmpx);
	info->dist.dy = (info->ray.x == 0) ? 0 : ((info->ray.y == 0) ? 1 : tmpy);
}

static void	set_step(t_info *info)
{
	if (info->ray.x < 0)
	{
		info->step.x = -1;
		info->dist.sx = (info->pos.x - info->map.x) * info->dist.dx;
	}
	else
	{
		info->step.x = 1;
		info->dist.sx = (info->map.x + 1.0 - info->pos.x) * info->dist.dx;
	}
	if (info->ray.y < 0)
	{
		info->step.y = -1;
		info->dist.sy = (info->pos.y - info->map.y) * info->dist.dy;
	}
	else
	{
		info->step.y = 1;
		info->dist.sy = (info->map.y + 1.0 - info->pos.y) * info->dist.dy;
	}
}

static void	set_dda(t_info *info)
{
	while (info->hit.f == 0)
	{
		if (info->dist.sx < info->dist.sy)
		{
			info->dist.sx += info->dist.dx;
			info->map.x += info->step.x;
			info->hit.s = 0;
		}
		else
		{
			info->dist.sy += info->dist.dy;
			info->map.y += info->step.y;
			info->hit.s = 1;
		}
		if (info->map.tab[info->map.y][info->map.x] == '1')
			info->hit.f = 1;
		if (info->map.tab[info->map.y][info->map.x] == '2')
			info->hit.f = 2;
	}
}

static void	set_range(t_info *info, t_sprite *sprite)
{
	pxy(pos);
	printf("%f\n", sprite->x);
	printf("%f\n", sprite->y);
	if (info->hit.s == 0)
	{
		sprite->dist = ((info->map.x - info->pos.x + (1 - info->step.x) / 2) \
						/ info->ray.x);
	}
	else
	{
		sprite->dist = ((info->map.y - info->pos.y + (1 - info->step.y) / 2) \
						/ info->ray.y);
	}
	sprite->lh = (int)(info->win.y / sprite->dist);
	sprite->ds = -(sprite->lh) / 2 + info->win.y / 2;
	sprite->de = sprite->lh / 2 + info->win.y / 2;
	if (sprite->ds < 0)
		sprite->ds = 0;
	if (sprite->de >= info->win.y)
		sprite->de = info->win.y - 1;
}
# if 0
static void	get_sprite_pos(t_sprite *sprite)
{
	if (!sprite->draw_x && !sprite->draw_y)
	{
		sprite->draw_x = ;
		sprite->draw_y = ;
	}
}
# endif
void	draw_sprite_col(t_info *info, t_sprite *sprite)
{
	int	x;
	
	x = -1;
	while(++x < info->win.x)
	{
	  	set_init(info, x);
		set_step(info);
		set_dda(info);
		if (info->hit.f == 2)
		{
			set_range(info, sprite);
			set_sprite(info, sprite, x);
		}
	}
	pxy(plane);	
	pxy(dir);	
}
