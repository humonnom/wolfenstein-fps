/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 21:45:02 by juepark           #+#    #+#             */
/*   Updated: 2021/03/12 21:45:02 by juepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_xpm(t_info *info, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_strncmp_reverse(file, ".xpm", 4))
		return (ERR);
	if ((fd = open(file, O_RDONLY)) == ERR)
		return (ERR);
	close(fd);
	img = mlx_xpm_file_to_image(info->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != PIXEL_SIZE || tab[1] != PIXEL_SIZE)
		return (ERR);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	img = ft_free(img);
	return (0);
}

int			parse_texture(
			t_info *info,
			unsigned int **adr,
			char *line,
			int *i)
{
	char	*file;
	int		get;

	if (*adr != NULL)
		return (TEX_DOUBLE);
	(*i) += 2;
	ft_spaceskip(line, i);
	if (!(file = ft_strdup(&line[*i])))
		return (TEX_ALLOC_FAIL);
	(*i) += ft_strlen(file);
	get = parse_xpm(info, adr, file);
	file = ft_free(file);
	if (get == ERR)
		return (TEX_INV);
	return (0);
}
