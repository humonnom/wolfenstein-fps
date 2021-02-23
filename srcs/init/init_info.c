#include "cub3d.h"

static void	init_else(t_info *info)
{
	t_time	time;
	t_list	*sprite;
	t_pos	pos;
	t_dir	dir;
	t_plane	plane;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	dir.d = '0';
	plane.x = PLANEX;
	plane.y = PLANEY;
	info->pos = pos;
	info->dir = dir;
	info->plane = plane;
	sprite = NULL;
	time.ms = SPEED;
	time.rs = TURN;
	info->time = time;
	info->sprite = sprite;
}

static void	init_map(t_info *info)
{
	t_map	map;
	t_tex	tex;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	map.sprite = 0;
	map.x = 0;
	map.y = 0;
	map.w = 0;
	map.h = 0;
	tex.c = NONE;
	tex.f = NONE;
	info->tex = tex;
	info->map = map;
}

static void	init_ray(t_info *info)
{
	t_camera	camera;
	t_dist	dist;
	t_step	step;
	t_screen	screen;

	camera.x = 0;
	camera.y = 0;
	dist.sx = 0;
	dist.sy = 0;
	dist.dx = 0;
	dist.dy = 0;
	dist.pw = 0;
	step.x = 0;
    step.y = 0;
	screen.ds = 0;
	screen.de = 0;
	screen.lh = 0;
	info->camera = camera;
	info->dist = dist;
	info->step = step;
}

static void	init_mlx(t_info *info)
{
	t_mlx	mlx;
	t_win	win;
	t_img	img;
	t_err	err;

	mlx.ptr = NULL;
	win.ptr = NULL;
	img.ptr = NULL;
	img.adr = NULL;
	win.x = 0;
	win.y = 0;
	err.n = 0;
	err.m = 0;
	err.p = 0;
	info->mlx = mlx;
	info->win = win;
	info->img = img;
	info->err = err;
}

/*******************************************
**-function: init info 
**-ar:	info 		->	structure(t_info)
**-return: non
**-call: ft_cubed()
*******************************************/
void		init_info(t_info *info)
{
	init_mlx(info);
	init_ray(info);
	init_map(info);
	init_else(info);
}
