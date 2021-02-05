#include "cub3d.h"


/*******************************************
-function: init structures(2)
-ar:	s 		->	structure(t_all)
		cub		->	char *, map file name
		save	-> 	save mode(0 or 1)
-return: non
-call: ft_cubed()
 *******************************************/

void	ft_init_map(t_all *s)
{
	t_map	map;
	t_tex	tex;

	map.tab = NULL;
	tex.n = NULL;
	tex.s = NULL;
	tex.e = NULL;
	tex.w = NULL;
	tex.i = NULL;
	map.spr = 0;
	map.x = 0;
	map.y = 0;
	map.w = 0;
	map.h = 0;
	tex.c = NONE;
	tex.f = NONE;
	s->tex = tex;
	s->map = map;
}

void	ft_init_else(t_all *s)
{
	t_tim	tim;
	t_spr	*spr;
	t_pos	pos;
	t_dir	dir;
	t_pla	pla;

	pos.x = 0;
	pos.y = 0;
	dir.x = 0;
	dir.y = 0;
	dir.d = '0';
	pla.x = PLANEX;
	pla.y = PLANEY;
	s->pos = pos;
	s->dir = dir;
	s->pla = pla;
	spr = NULL;
	tim.now = 0;
	tim.old = 0;
	tim.frame = 0;
	tim.ms = 0;
	tim.rs = 0;
	s->tim = tim;
	s->spr = spr;
}

void	ft_init_ray(t_all *s)
{
	t_cmr	cmr;
	t_dst	dst;
	t_stp	stp;
	t_scr	scr;

	cmr.x = 0;
	cmr.y = 0;
	dst.sx = 0;
	dst.sy = 0;
	dst.dx = 0;
	dst.dy = 0;
	dst.pw = 0;
	stp.x = 0;
    stp.y = 0;
	scr.ds = 0;
	scr.de = 0;
	scr.lh = 0;
	s->cmr = cmr;
	s->dst = dst;
	s->stp = stp;
}

void	ft_init_mlx(t_all *s)
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

int 	ft_init(t_all *s)
{
	ft_init_mlx(s);
	ft_init_ray(s);
	ft_init_map(s);
	ft_init_else(s);
	return (DONE);
}
