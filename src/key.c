#include "cub3d.h"

/*******************************************
-function: close window
-ar:	s 		->	structure(t_all)
		win		-> 	window number
-return: int (1 or)
-call: non
 *******************************************/
int		ft_close(t_all *s, int win)
{
	int i;

	i = -1;
	while (++i < s->map.h)
		s->map.tab[i] = ft_free(s->map.tab[i]);
	s->map.tab = ft_free(s->map.tab);
	s->tex.n = ft_free(s->tex.n);
	s->tex.s = ft_free(s->tex.s);
	s->tex.e = ft_free(s->tex.e);
	s->tex.w = ft_free(s->tex.w);
	s->tex.i = ft_free(s->tex.i);
	if (win == 1)
		mlx_destroy_window(s->mlx.ptr, s->win.ptr);
	s->mlx.ptr = ft_free(s->mlx.ptr);
	exit(0);
	return(1);
}

/*****************************************
**-function: move
**-ar:	s 		->	structure(t_all)
**		c		-> 	plus/minus flag
**-return: non
**-call: ft_slist()
******************************************/

void	ft_move(t_all *s, double c)
{
	int tmp;

	if ((int)c == 1)
	{
		tmp = (int)(s->pos.x + s->dir.x * s->tim.ms);
		if(tmp < s->map.w && tmp > 0 && \
				s->map.tab[tmp][(int)(s->pos.y)] != '1')
			s->pos.x += s->dir.x * s->tim.ms;
		tmp = (int)(s->pos.y + s->dir.y * s->tim.ms);
		if(tmp < s->map.h && tmp > 0 && \
				s->map.tab[(int)(s->pos.x)][tmp] != '1')
			s->pos.y += s->dir.y * s->tim.ms;
	}
	else
	{
		tmp = (int)(s->pos.x - s->dir.x * s->tim.ms);
		if(tmp < s->map.w && tmp > 0 && \
				s->map.tab[tmp][(int)(s->pos.y)] != '1')
			s->pos.x -= s->dir.x * s->tim.ms;
		tmp = (int)(s->pos.y - s->dir.y * s->tim.ms);
		if(tmp < s->map.h && tmp > 0 && \
				s->map.tab[(int)(s->pos.x)][tmp] != '1')
			s->pos.y -= s->dir.y * s->tim.ms;
	}
}

/*******************************************
**-function: rotate
**-ar:	s 		->	structure(t_all)
**		c		-> 	plus/minus flag
**-return: non
**-call:
********************************************/
void	ft_rotate(t_all *s, double c)
{
	double olddir;
	double oldplane;
	double rotspeed;

//	if ((int)c == -1)
//	{
//		olddir = s->dir.x;
//		rotspeed = s->tim.rs;
//		s->dir.x = s->dir.x * cos(-rotspeed) - \
//				   s->dir.y * sin(-rotspeed);
//		s->dir.y = olddir * sin(-rotspeed) + \
//				   s->dir.y * cos(-rotspeed);
//		oldplane = s->pla.x;
//		s->pla.x = s->pla.x * cos(-rotspeed) - \
//				   s->pla.y * sin(-rotspeed);
//		s->pla.y = oldplane * sin(rotspeed) +\
//				   s->pla.y * cos(-rotspeed);
//	}

	rotspeed = s->tim.rs * c;
	olddir = s->dir.x;
	s->dir.x = s->dir.x * cos(rotspeed) - s->dir.y * sin(rotspeed);
	s->dir.y = olddir * sin(rotspeed) + s->dir.y * cos(rotspeed);
	oldplane = s->pla.x;
	s->pla.x = s->pla.x * cos(rotspeed) - s->pla.y * sin(rotspeed);
	s->pla.y = oldplane * sin(rotspeed) + s->pla.y * cos(rotspeed);
}

/*******************************************
-function: strafe
-ar:	s 		->	structure(t_all)
		c		-> 	plus/minus flag
-return: non
-call: ft_slist()
 *******************************************/
void	ft_strafe(t_all *s, double c)
{
	int tmp;
	
	if ((int)c == 1)
	{
		tmp = (int)(s->pos.x - s->dir.y * s->tim.ms);
		if(tmp < s->map.w && tmp > 0 && \
				s->map.tab[tmp][(int)(s->pos.y)] != '1')
			s->pos.x -= s->dir.y * s->tim.ms;
		tmp = (int)(s->pos.y + s->dir.x * s->tim.ms);
		if(tmp < s->map.h && tmp > 0 && \
				s->map.tab[(int)(s->pos.x)][tmp] != '1')
			s->pos.y += s->dir.x * s->tim.ms;
	}
	else
	{
		tmp = (int)(s->pos.x + s->dir.y * s->tim.ms);
		if(tmp < s->map.w && tmp > 0 && \
				s->map.tab[tmp][(int)(s->pos.y)] != '1')
			s->pos.x += s->dir.y * s->tim.ms;
		tmp = (int)(s->pos.y - s->dir.x * s->tim.ms);
		if(tmp < s->map.h && tmp > 0 && \
				s->map.tab[(int)(s->pos.x)][tmp] != '1')
			s->pos.y -= s->dir.x * s->tim.ms;
	}
}

/*******************************************
-function: key handling
-ar:	key 	->	pressed key
		arg		-> 	???
-return: int (1)
-call:	ft_close()
		ft_move()
		ft_strafe()
		ft_move()
		ft_rotate()
		ft_draw()
 *******************************************/
int		ft_key(int key, t_all *s)
{
	if (key == ESC)
		ft_close(s, 1);
	else if(key == W)
		ft_move(s, 1);
	else if(key == A)
		ft_strafe(s, -1);
	else if(key == S)
		ft_move(s, -1);
	else if(key == D)
		ft_strafe(s, 1);
	else if(key == LEFT)
		ft_rotate(s, -1);
	else if(key == RIGHT)
		ft_rotate(s, 1);
	ft_draw(s);
	return (1);
}
