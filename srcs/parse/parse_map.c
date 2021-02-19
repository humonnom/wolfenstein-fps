#include "cub3d.h"
int		parse_map(t_info *info, char *line, int *i)
{
	char	**tmp;
	int		j;

	info->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (info->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	j = info->map.h + 1;
	while (--j > 0)
		tmp[j] = info->map.tab[j - 1];
	if ((tmp[0] = parse_map_part(info, line, i)) == NULL)
	{
		tmp = ft_free(tmp);
		return (MAP_INV);
	}	
	tmp[info->map.h + 1] = NULL;
	if (info->map.h > 0)
		free(info->map.tab);
	info->map.tab = tmp;
	info->map.h++;
	if ((info->map.w = get_part_len(info, line)) == -1)
		return (MAP_SHAPE);
	return (0);
}
