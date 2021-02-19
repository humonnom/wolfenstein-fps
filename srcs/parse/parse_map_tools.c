#include "cub3d.h"
int		get_part_len(t_info *info, char *line)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if (ft_strchr("012NSWE", line[i]))
			count++;
		i++;
	}
	if (info->map.w != 0 && info->map.w != count)
		return (-1);
	return(count);
}

