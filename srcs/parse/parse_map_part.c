#include "cub3d.h"

static int	get_str_len_exce(const char *str, char c, int space_flag)
{
	int count;
	int i;

	count = 0;
	i = -1;
	if (space_flag < 0)
		count = ft_strlen(str);
	while (space_flag >= 0 && str[++i])
	{
		if (str[i] != c)
			count++;
	}
	return (count);
}

static char	*get_str_cpy(char *str, int space_flag)
{
	int i;
	int step;
	char *str_cpy;

	if (!(str_cpy = ft_strdup(str)))
		return (NULL);
	i = space_flag;
	step = 2;
	while (space_flag >= 0 && str_cpy[i])
	{
		if (str_cpy[i] == ' ')
			str_cpy[i] = '3';	
		i += step;
	}
	//printf("str_cpy(' ' -> 3): [%s]\n", str_cpy);
	return (str_cpy);
}

char	*parse_map_part(t_info *info, char *line)
{
	char	*parsed;
	char	*line_cpy;
	int		j;
	int		index;
	int		parsed_len;

	j = -1;
	////ps(line);
	//ps("[parse_map_part] 49\n");
	if (!(line_cpy = get_str_cpy(line, info->map.space)))
		return (0);
	//ps("[line_cpy] : ");ps(line_cpy);
	parsed_len = get_str_len_exce(line_cpy, '3', info->map.space);
	if (!(parsed = malloc(sizeof(char) * (parsed_len + 1))))
		return (0);
	//ps("[parse_map_part] 56\n");
	index = -1;
	//ps("\t");printf("[%s\n]", parsed);
	while (line_cpy[++index])
	{
		//printf("line_cpy[%d] : [%c]\n", index, line_cpy[index]);
		//ps("[parse_map_part] 56\n");
		if (ft_strchr("012NSWE ", line_cpy[index]))
			parsed[++j] = line_cpy[index];
		else if (line_cpy[index] != '3')
		{
			//ps("[parse_map_part] 67\n");
			free(line_cpy);
			free(parsed);
			return(NULL);
		}	
	}
	//ps("[parse_map_part] 72\n");
	parsed[++j] = '\0';
//	printf("parsed[i]: %c\n", parsed[*i]);
	//ps("[parse_map_part] 75\n");
//	printf("[parsed_line] :%s\n", parsed);
	ft_free(line_cpy);
	return (parsed);
}
