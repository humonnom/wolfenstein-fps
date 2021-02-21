#include "cub3d.h"
int		get_part_len(t_info *info, char *line)
{
	int	i;
	int count;

	i = -1;
	count = 0;
	while(line[++i])
	{
		if (ft_strchr("0123NSWE", line[i]))
			count++;
	}
	pd(count);
	if (info->map.w < count)
		info->map.w = count;
	return(count);
}

