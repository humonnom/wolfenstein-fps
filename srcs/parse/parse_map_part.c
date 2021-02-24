#include "cub3d.h"
static void	get_str_cpy(char *str, char **str_cpy)
{
	int i;
	char *tmp;

	tmp = ft_strdup(str);
	i = -1;
	while (tmp[++i] && tmp[i + 1])
	{
		if (ft_strncmp(&tmp[i], "  ", 2) == 0)
			tmp[i++] = '3';
	}
	*str_cpy = tmp;
}

static int	get_str_len_exce(char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (!ft_strchr(&c, str[i]))
			count++;
	}
	return (count);
}

char	*parse_map_part(t_info *info, char *line, int *i)
{
	char	*part;
	char	*line_cpy;
	int	j;
	int	index;

	j = -1;
	line_cpy = NULL;
	if (line[0] == '\0')
		printf("=====================================\n");
	get_str_cpy(line, &line_cpy);
	if (!(part = malloc(sizeof(char) * (get_str_len_exce(line_cpy, ' ') + 1))))
		return (0);
	index = -1;
	while (line_cpy[++index])
	{
		if (line_cpy[index] == '2')
			info->map.sprite++;
		if (ft_strchr("012NSWE", line_cpy[index]))
			part[++j] = line_cpy[index];
		else if (line_cpy[index] == '3')
			part[++j] = ' ';
		else if (line_cpy[index] != ' ')
			return(ft_free(part));
	}
	part[++j] = '\0';
	(*i) += ft_strlen(line);
	return (part);
}
