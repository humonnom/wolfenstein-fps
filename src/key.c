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
	while (++i < s->map.y)
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

/*******************************************
-function: move
-ar:	s 		->	structure(t_all)
		c		-> 	plus/minus flag
-return: non
-call: ft_slist()
 *******************************************/
void	ft_move(t_all *s, double c)
{
	s->pos.x += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.x -= c * (s->dir.x * SPEED / 100);
	s->pos.y += c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
		s->pos.y -= c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '2')
	{
		s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] = '0';
		s->map.spr--;
		ft_slist(s);
	}
	printf("move\t");
	printf("s->pos.x = %f, s->pos.y = %f\n", s->pos.x, s->pos.y);  
	printf("\t\ts->dir.x = %f, s->dir.y = %f\n", s->dir.x, s->dir.y);  
}

/*******************************************
-function: rotate
-ar:	s 		->	structure(t_all)
		c		-> 	plus/minus flag
-return: non
-call:
 *******************************************/
void	ft_rotate(t_all *s, double c)
{
	double	dist;
	s->dir.x = s->dir.x * cos(c * TURN) - s->dir.y * sin(c * TURN);
	s->dir.y = s->dir.y * cos(c * TURN) + s->dir.x * sin(c * TURN);
	dist = hypot(s->dir.x, s->dir.y);
	s->dir.x /= dist;
	s->dir.y /= dist;
	printf("rotate\t");
	printf("s->pos.x = %f, s->pos.y = %f\n", s->pos.x, s->pos.y);  
	printf("\t\ts->dir.x = %f, s->dir.y = %f\n", s->dir.x, s->dir.y);  
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
	s->pos.x -= c * (s->dir.y * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
	s->pos.x += c * (s->dir.y * SPEED / 100);
	s->pos.y += c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '1')
	s->pos.y -= c * (s->dir.x * SPEED / 100);
	if (s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] == '2')
	{
		s->map.tab[(int)floor(s->pos.y)][(int)floor(s->pos.x)] = '0';
		s->map.spr--;
		ft_slist(s);
	}
	printf("strafe\t");
	printf("s->pos.x = %f, s->pos.y = %f\n", s->pos.x, s->pos.y);  
	printf("\t\ts->dir.x = %f, s->dir.y = %f\n", s->dir.x, s->dir.y);  
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
