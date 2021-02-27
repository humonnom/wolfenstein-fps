#include "cub3d.h"
static	void	get_space_flag(t_info *info, char *line)
{
	unsigned long	even;
	unsigned long	odd;
	int				i;

	even = 0;
	odd = 0;
	i = -1;
	info->map.space = -1;
	while (line[++i])
	{
		if (!(i % 2) && line[i] == ' ')
			even++;
		if ((i % 2) && line[i] == ' ')
			odd++;
	}
//	pd((int)odd);
//	pd((int)even);
	if (ft_strlen(line) / 2 <= even + 1)
		info->map.space = 0;
	if (ft_strlen(line) / 2 <= odd + 1)
		info->map.space = 1;
}


int		parse_map(t_info *info, char *line)
{
	char	**buf;
	int		j;

	if (info->map.space == -2)
		get_space_flag(info, line);
	info->err.m = 1;
	if (!(buf = malloc(sizeof(char *) * (info->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	//ps("[parse map] 29\n");
	j = info->map.h + 1;
	while (--j > 0)
		buf[j] = info->map.tab[j - 1];
	//ps("[parse map] 33\n");
	if ((buf[0] = parse_map_part(info, line)) == NULL)
	{
		//ps("[parse map] 36\n");
		free(buf);
		return (MAP_INV);
	}
	//printf("[parse map] buf[0]:%s\n", buf[0]);
	buf[info->map.h + 1] = NULL;
	if (info->map.h > 0)
		free(info->map.tab);
	//ps("[parse map] 44\n");
	info->map.tab = buf;
	info->map.h++;
	info->map.w = ft_max(info->map.w, ft_strlen(info->map.tab[0]));
	//ps("[parse_map] end\n");
	return (info->err.n);
}
