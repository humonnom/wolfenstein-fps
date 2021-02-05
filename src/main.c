#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_all s;

	if (!(argc >= 2 && argc <= 3))
		return(ft_strerr(ARG_NUM));
	if (!(argc >= 2 && !ft_strncmp_reverse(argv[1], ".cub", 4)))
		return(ft_strerr(MAP_NAME));
	if (!(argc == 2 || !ft_strncmp(argv[2], "--save", 6)))
		return(ft_strerr(SAVE_OPT));
	if (!ft_init(&s))
		return(ft_strerr(INIT_FAIL));
	cub3d_loop(s, argv[1], argc == 3);
	return(0);
}
