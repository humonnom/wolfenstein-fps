#include "cub3d.h"

int		cub3d_loop(t_all s, char *cub, int save)
{
	s.mlx.ptr = mlx_init();
	if (parse_file(&s, cub) == -1)
		return (exit_game(&s, 0));
	if (save == 1)
		printf("This is save mode\n");
	s.win.ptr = mlx_new_window(s.mlx.ptr, s.win.x, s.win.y, "cub3D");
	draw_window(&s);
	mlx_hook(s.win.ptr, KEY, 0, get_key, &s);	
	mlx_hook(s.win.ptr, EXIT_BTN, 0, exit_game, &s);	
	mlx_loop(s.mlx.ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_all	s;

	if (!(argc >= 2 && argc <= 3))
		return(err_filter(ARG_NUM));
	if (!(argc >= 2 && !ft_strncmp_reverse(argv[1], ".cub", 4)))
		return(err_filter(MAP_NAME));
	if (!(argc == 2 || !ft_strncmp(argv[2], "--save", 6)))
		return(err_filter(SAVE_OPT));
	s.pid = -1;
//	s.pid = fork();
//	if (s.pid == 0)
//		system("afplay ../bonus/sound/human_dream.mp3");
	if (s.pid != 0)
	{
		if (!init_all(&s))
			return(err_filter(INIT_FAIL));
		cub3d_loop(s, argv[1], argc == 3);
	}
	return(0);
}
