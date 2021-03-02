#include "cub3d.h"

/*******************************************
-function: close window
-ar:	s 		->	structure(t_info)
		win		-> 	window number
-return: int (1 or)
-call: non
 *******************************************/
#include <signal.h>
#include <sys/types.h>

int		exit_game(t_info *info, int win)
{
//	t_list	*cur;
//	t_list	*tmp;

	ft_2strfree(info->map.tab);
	info->tex.n = ft_free(info->tex.n);
	info->tex.s = ft_free(info->tex.s);
	info->tex.e = ft_free(info->tex.e);
	info->tex.w = ft_free(info->tex.w);
	info->tex.i = ft_free(info->tex.i);
	if (win == 1)
		mlx_destroy_window(info->mlx.ptr, info->win.ptr);
	free(info->mlx.ptr);
	if (info->pid > 0)
		kill(info->pid + 1, SIGTERM);
//	cur = info->sprite;
//	while (cur)
//	{
//		tmp = cur->next;
//		ft_lstdelone(cur, &free);
//		cur = tmp;
//	}
//	while (1)
//		;
	exit(0);
	return(1);
}
