#include "cub3d.h"

/*******************************************
-function:	
-ar:	s 		->	structure(t_all)
-return: non
-call:	ft_screen_col()
		ft_sprite()
 *******************************************/
void	ft_screen(t_all *s)
{
	int		tab[3];
	int		x;

	s->img.ptr = mlx_new_image(s->mlx.ptr, s->win.x, s->win.y);
	s->img.adr = (unsigned int *)mlx_get_data_addr(s->img.ptr, &tab[0], &tab[1], &tab[2]);
	x = -1;
	while(++x < s->win.x)
	{
		ft_screen_col(s, x);
	}
	ft_minimap(s);
//	ft_sprite(s);
	ft_time(s);
}

void	ft_time(t_all *s)
{
	s->tim.old = s->tim.now;
	s->tim.now = clock();
	s->tim.frame = (s->tim.now - s->tim.old) / 1000.0;
	s->tim.ms = SPEED;//s->tim.frame * 5.0;	
	s->tim.rs = TURN;//s->tim.frame * 3.0;	
}

