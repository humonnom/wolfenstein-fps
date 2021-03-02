#include "cub3d.h"
/*****************************************
**-function: move
**-ar:	s 		->	structure(t_info)
**		c		-> 	plus/minus flag
**-return: non
**-call: ft_slist()
******************************************/
static void	handle_move(t_info *info, int c)
{
	int x;
	int y;

	x = info->pos.x + info->dir.x * info->time.ms * c;
	y = info->pos.y + info->dir.y * info->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < info->map.w && y < info->map.h &&\
		info->map.tab[y][x] != '1' &&\
		info->map.tab[y][x] != '2')
	{
		info->pos.x += info->dir.x * info->time.ms * c;
		info->pos.y += info->dir.y * info->time.ms * c;
	}
}

/*******************************************
**-function: rotate
**-ar:	s 		->	structure(t_info)
**		c		-> 	plus/minus flag
**-return: non
**-call:
********************************************/
static void	handle_rotate(t_info *info, double c)
{
	double olddir;
	double oldplane;
	double rotspeed;

	rotspeed = info->time.rs * c;
	olddir = info->dir.x;
	info->dir.x = info->dir.x * cos(rotspeed) - info->dir.y * sin(rotspeed);
	info->dir.y = olddir * sin(rotspeed) + info->dir.y * cos(rotspeed);
	oldplane = info->plane.x;
	info->plane.x = info->plane.x * cos(rotspeed) - info->plane.y * sin(rotspeed);
	info->plane.y = oldplane * sin(rotspeed) + info->plane.y * cos(rotspeed);
}

/*******************************************
-function: strafe
-ar:	s 		->	structure(t_info)
		c		-> 	plus/minus flag
-return: non
-call: ft_slist()
 *******************************************/
static void	handle_strafe(t_info *info, int c)
{
	int x;
	int y;

	x = info->pos.x + info->dir.y * info->time.ms * -c;
	y = info->pos.y + info->dir.x * info->time.ms * c;
	if (x > 0 && y > 0 &&\
		x < info->map.w && y < info->map.h &&\
		info->map.tab[y][x] != '1' &&\
		info->map.tab[y][x] != '2')
	{
		info->pos.x += info->dir.y * info->time.ms * -c;
		info->pos.y += info->dir.x * info->time.ms * c;
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
int		get_key(int key, t_info *info)
{
	if (key == ESC)
		exit_game(info, 1);
	else if(key == W)
		handle_move(info, 1);
	else if(key == S)
		handle_move(info, -1);
	else if(key == A)
		handle_strafe(info, 1);
	else if(key == D)
		handle_strafe(info, -1);
	else if(key == LEFT)
		handle_rotate(info, 1);
	else if(key == RIGHT)
		handle_rotate(info, -1);
//	else if(key == VOLUME_UP)
//		handle_sound(1);
//	else if(key == VOLUME_DOWN)
//		handle_sound(-1);
	draw_view(info, PRINT);
	return (DONE);
}
