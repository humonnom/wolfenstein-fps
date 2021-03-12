/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 20:42:17 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 20:42:18 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	print_err_head(int err)
{
	if (err == FILE_OPEN)
		printf("Couldn't open file (FD)\n");
	if (err == FILE_PARSE)
		printf("Couldn't parse file (GNL)\n");
	if (err == RES_DOUBLE)
		printf("Resolution specified twice\n");
	if (err == RES_INV)
		printf("Invalid resolution\n");
	if (err == FC_DOUBLE)
		printf("Floor/ceiling specified twice\n");
	if (err == FC_INV)
		printf("Invalid floor/ceiling line\n");
	if (err == TEX_DOUBLE)
		printf("Texture path specified twice\n");
	if (err == TEX_ALLOC_FAIL)
		printf("Malloc fail (texture path)\n");
	if (err == TEX_INV)
		printf("Invalid texture image\n");
}

static void	print_err_mid(int err)
{
	if (err == LINE_INV)
		printf("Invalid line in file\n");
	if (err == MAP_ALLOC_FAIL)
		printf("Malloc fail (map table)\n");
	if (err == MAP_INV)
		printf("Invalid map\n");
	if (err == MAP_SHAPE)
		printf("Map isn't a rectangle\n");
	if (err == RES_MISSING)
		printf("No resolution specified\n");
	if (err == TEX_MISSING)
		printf("Missing texture\n");
	if (err == FC_MISSING)
		printf("Missing floor/ceiling color\n");
	if (err == POS_MISSING)
		printf("No starting position\n");
	if (err == POS_DOUBLE)
		printf("Multiple starting positions\n");
	if (err == MAP_CRACK)
		printf("Map isn't surrounded by walls\n");
}

static void	print_err_tail(int err)
{
	if (err == MARK_ERR)
		printf("Minimap mark fail\n");
	if (err == ARG_NUM)
		printf("Invalid argument number\n");
	if (err == MAP_NAME)
		printf("Invalid map name\n");
	if (err == SAVE_OPT)
		printf("Invalid save option\n");
	if (err == INIT_FAIL)
		printf("Init fail\n");
	if (err == SPRITE_DOUBLE)
		printf("Sprite specified twice\n");
}

int			report_err(int err)
{
	if (err == -1)
		printf("Error\n");
	else if (err > -11)
		print_err_head(err);
	else if (err > -21)
		print_err_mid(err);
	else
		print_err_tail(err);
	return (-1);
}
