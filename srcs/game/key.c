#include "cub3d.h"
/*****************************************
**-function: move
**-ar:	s 		->	structure(t_all)
**		c		-> 	plus/minus flag
**-return: non
**-call: ft_slist()
******************************************/
static void	handle_move(t_all *s, int c)
{
	int x;
	int y;

	x = s->pos.x + s->dir.x * s->time.ms * c;
	y = s->pos.y + s->dir.y * s->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < s->map.w && y < s->map.h &&\
		s->map.tab[y][x] != '1')
	{
		s->pos.x += s->dir.x * s->time.ms * c;
		s->pos.y += s->dir.y * s->time.ms * c;
	}
}

/*******************************************
**-function: rotate
**-ar:	s 		->	structure(t_all)
**		c		-> 	plus/minus flag
**-return: non
**-call:
********************************************/
static void	handle_rotate(t_all *s, double c)
{
	double olddir;
	double oldplane;
	double rotspeed;

	rotspeed = s->time.rs * c;
	olddir = s->dir.x;
	s->dir.x = s->dir.x * cos(rotspeed) - s->dir.y * sin(rotspeed);
	s->dir.y = olddir * sin(rotspeed) + s->dir.y * cos(rotspeed);
	oldplane = s->plane.x;
	s->plane.x = s->plane.x * cos(rotspeed) - s->plane.y * sin(rotspeed);
	s->plane.y = oldplane * sin(rotspeed) + s->plane.y * cos(rotspeed);
}

/*******************************************
-function: strafe
-ar:	s 		->	structure(t_all)
		c		-> 	plus/minus flag
-return: non
-call: ft_slist()
 *******************************************/
static void	handle_strafe(t_all *s, int c)
{
	int x;
	int y;

	x = s->pos.x + s->dir.y * s->time.ms * -c;
	y = s->pos.y + s->dir.x * s->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < s->map.w && y < s->map.h &&\
		s->map.tab[y][x] != '1')
	{
		s->pos.x += s->dir.y * s->time.ms * -c;
		s->pos.y += s->dir.x * s->time.ms * c;
	}
}

/*******************************************
-function: key handling
-ar:	key 	->	pressed key
		arg		-> 	???
-return: int (1)
-call:	exit_game()
		handle_move()
		handle_strafe()
		handle_move()
		handle_rotate()
		handle_draw()
 *******************************************/
int		get_key(int key, t_all *s)
{
	if (key == ESC)
		exit_game(s, 1);
	else if(key == W)
		handle_move(s, 1);
	else if(key == S)
		handle_move(s, -1);
	else if(key == A)
		handle_strafe(s, 1);
	else if(key == D)
		handle_strafe(s, -1);
	else if(key == LEFT)
		handle_rotate(s, 1);
	else if(key == RIGHT)
		handle_rotate(s, -1);
	else if(key == VOLUME_UP)
		handle_sound(1);
	else if(key == VOLUME_DOWN)
		handle_sound(-1);
	draw_window(s);
	return (DONE);
}
