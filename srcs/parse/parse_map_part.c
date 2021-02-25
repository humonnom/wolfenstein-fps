#include "cub3d.h"

static int	get_str_len_exce(char *str, char c)
{
	int count;
	int i;

	count = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] != c)
			count++;
	}
	return (count);
}

static int	get_str_cpy(char *str, char **str_cpy, int space_flag)
{
	int i;
	
	if (!(*str_cpy = ft_strdup(str)))
		return (0);
	if (space_flag)
		return (ft_strlen(*str_cpy));
	i = -1;
	while (*str_cpy[++i] && *str_cpy[i + 1])
	{
		if (ft_strncmp(str_cpy[i], "  ", 2) == 0)
			*str_cpy[++i] = '3';
	}
	return (get_str_len_exce(*str_cpy, ' ')); 
}

char	*parse_map_part(t_info *info, char *line, int *i)
{
	char	*parsed;
	char	*line_cpy;
	int		j;
	int		index;
	int		parsed_len;

	j = -1;
	line_cpy = NULL;
	if (!(parsed_len = get_str_cpy(line, &line_cpy, info->map.space)))
		return (0);
	if (!(parsed = malloc(sizeof(char) * (parsed_len + 1))))
		return (0);
	index = -1;
	while (line_cpy[++index])
	{
		if (line_cpy[index] == '2')
			info->map.sprite++;
		if (ft_strchr("012NSWE", line_cpy[index]))
			parsed[++j] = line_cpy[index];
		else if (line_cpy[index] == ' ')
			parsed[++j] = ' ';
		else if (line_cpy[index] != '3')
			return(ft_free(parsed));
	}
//	printf("other character\n");
	parsed[++j] = '\0';
	(*i) += ft_strlen(line);
	ft_free(line_cpy);
	return (parsed);
}
