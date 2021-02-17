#include "cub3d.h"

/*******************************************
-function: close window
-ar:	s 		->	structure(t_all)
		win		-> 	window number
-return: int (1 or)
-call: non
 *******************************************/
#include <signal.h>
#include <sys/types.h>

int		exit_game(t_all *s, int win)
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
	kill(s->pid + 1, SIGTERM);
	exit(0);
	return(1);
}
