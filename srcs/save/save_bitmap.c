/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:43:50 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:43:51 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		save_bitmap(t_info *info)
{
	int ret;

	ret = 0;
	draw_view(info, NON_PRINT);
	if ((make_bitmap_file(info)))
		report_err(FILE_OPEN);
	exit_game(info, 0);
	return (ret);
}
