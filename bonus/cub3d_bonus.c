/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:30:23 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 22:36:47 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int		get_zbuf(double **zbuf, int width)
{
	double *buf;

	if (!(buf = (double *)malloc(sizeof(double) * width)))
		return (1);
	buf = ft_memset((void *)buf, 0, width);
	*zbuf = buf;
	return (0);
}

int				cub3d_loop(t_info info, char *cub, int save)
{
	int	ret;

	ret = 0;
	info.mlx.ptr = mlx_init();
	if ((ret = parse_file(&info, cub)))
	{
		report_err(ret);
		return (exit_game(&info, 0));
	}
	if (get_zbuf(&(info.zbuf), info.win.x))
		return (exit_game(&info, 0));
	if (save == 1)
		save_bitmap(&info);
	info.win.ptr = \
	mlx_new_window(info.mlx.ptr, info.win.x, info.win.y, "cub3D");
	draw_view(&info, PRINT);
	mlx_hook(info.win.ptr, KEY_PRESS, 0, &get_key, &info);
	mlx_hook(info.win.ptr, KEY_RELEASE, 0, &get_key, &info);
	mlx_hook(info.win.ptr, EXIT_BTN, (1L << 17), &exit_game, &info);
	mlx_loop(info.mlx.ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	t_info	info;

	if (!(argc >= 2 && argc <= 3))
		return (report_err(ARG_NUM));
	if (!(argc >= 2 && !ft_strncmp_reverse(argv[1], ".cub", 4)))
		return (report_err(MAP_NAME));
	if (!(argc == 2 || !ft_strncmp(argv[2], "--save", 6)))
		return (report_err(SAVE_OPT));
	info.pid = -1;
	if (argc == 2)
		info.pid = fork();
	if (info.pid == 0)
		system("afplay ./sound/human_dream.mp3");
	if (info.pid != 0)
	{
		init_info(&info);
		return (cub3d_loop(info, argv[1], argc == 3));
	}
	return (0);
}
