#include "cub3d.h"

/*******************************************
-function: init structures(2)
-ar:	s 		->	structure(t_all)
		cub		->	char *, map file name
		save	-> 	save mode(0 or 1)
-return: non
-call: ft_cubed()
 *******************************************/
static void	init_map(t_all *s)
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
	s->tex = tex;
	s->map = map;
}

static void	init_else(t_all *s)
{
	t_time	time;
	t_sprite	*sprite;
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
	s->pos = pos;
	s->dir = dir;
	s->plane = plane;
	sprite = NULL;
	time.ms = SPEED;
	time.rs = TURN;
	s->time = time;
	s->sprite = sprite;
}

static void	init_ray(t_all *s)
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
	s->camera = camera;
	s->dist = dist;
	s->step = step;
}

static void	init_mlx(t_all *s)
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
	s->mlx = mlx;
	s->win = win;
	s->img = img;
	s->err = err;
}

int			init_all(t_all *s)
{
	init_mlx(s);
	init_ray(s);
	init_map(s);
	init_else(s);
	return (DONE);
}
