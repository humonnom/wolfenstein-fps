#include "cub3d.h"
static int		get_part_len(t_info *info, char *line)
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

static char	*parse_map_part(t_info *info, char *line, int *i)
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
