#include "cub3d.h"
int		parse_map(t_info *info, char *line, int *i)
{
	char	**buf;
	int		j;

	info->err.m = 1;
	if (!(buf = malloc(sizeof(char *) * (info->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	j = info->map.h + 1;
	while (--j > 0)
		buf[j] = info->map.tab[j - 1];
	if ((buf[0] = parse_map_part(info, line, i)) == NULL)
	{
		buf = ft_free(buf);
		return (MAP_INV);
	}
	buf[info->map.h + 1] = NULL;
	if (info->map.h > 0)
		free(info->map.tab);
	info->map.tab = buf;
	info->map.h++;
	info->map.w = ft_max(info->map.w, ft_strlen(info->map.tab[0]));
	return (0);
}
