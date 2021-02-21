#include "cub3d.h"

int		cub3d_loop(t_info info, char *cub, int save)
{
	info.mlx.ptr = mlx_init();
	if (parse_file(&info, cub))
	{
		ps("[cub3d.c]\n");
		report_err(FILE_PARSE);
		return (exit_game(&info, 0));
	}
	if (save == 1)
		save_bitmap(&info);
	info.win.ptr = mlx_new_window(info.mlx.ptr, info.win.x, info.win.y, "cub3D");
	draw_view(&info, PRINT);
	mlx_hook(info.win.ptr, KEY, 0, get_key, &info);	
	mlx_hook(info.win.ptr, EXIT_BTN, 0, exit_game, &info);	
	mlx_loop(info.mlx.ptr);
	return (1);
}

int		main(int argc, char **argv)
{
	t_info	info;

	if (!(argc >= 2 && argc <= 3))
		return(report_err(ARG_NUM));
	if (!(argc >= 2 && !ft_strncmp_reverse(argv[1], ".cub", 4)))
		return(report_err(MAP_NAME));
	if (!(argc == 2 || !ft_strncmp(argv[2], "--save", 6)))
		return(report_err(SAVE_OPT));
	info.pid = -1;
//	info.pid = fork();
//	if (info.pid == 0)
//		system("afplay ../bonus/sound/human_dream.mp3");
	if (info.pid != 0)
	{
		init_info(&info);
		cub3d_loop(info, argv[1], argc == 3);
	}
	return(0);
}
