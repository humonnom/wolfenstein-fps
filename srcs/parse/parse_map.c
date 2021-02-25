#include "cub3d.h"
static	void	get_space_flag(t_info *info, char *line, int i)
{
	unsigned long	space_num;

	space_num = 0;
	i--;
	while (line[++i])
	{
		if (line[i] == ' ')
			space_num++;
	}
	if (ft_strlen(line) / 2 <= space_num + 1)
		info->map.space = 1;
}


int		parse_map(t_info *info, char *line, int *i)
{
	char	**buf;
	int		j;

	get_space_flag(info, line, *i);
	info->err.m = 1;
	if (!(buf = malloc(sizeof(char *) * (info->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	j = info->map.h + 1;
	while (--j > 0)
		buf[j] = info->map.tab[j - 1];
	if ((buf[0] = parse_map_part(info, line, i)) == NULL)
	{
		free(buf);
		return (MAP_INV);
	}
	buf[info->map.h + 1] = NULL;
	if (info->map.h > 0)
		free(info->map.tab);
	info->map.tab = buf;
	info->map.h++;
	info->map.w = ft_max(info->map.w, ft_strlen(info->map.tab[0]));
	ps("[parse_map]\n");
	return (0);
}
