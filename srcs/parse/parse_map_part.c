#include "cub3d.h"
char	*parse_map_part(t_info *info, char *line, int *i)
{
	char	*part;
	int		j;

	if (!(part = malloc(sizeof(char) * (get_part_len(info, line) + 1))))
		return (0);
	j = 0;
	while (line[*i] != '\0')
	{
		if (ft_strchr("01NSWE", line[*i]))
			part[j++] = line[*i];
		else if (line[*i] == '2')
		{
			part[j++] = line[*i];
			info->map.sprite++;
		}
		else if (line[*i] != ' ')
			return(part = ft_free(part));
		(*i)++;
	}
	part[j] = '\0';
	return(part);
}

