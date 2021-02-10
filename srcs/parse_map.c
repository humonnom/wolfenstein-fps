#include "cub3d.h"
static int		parse_slablen(t_all *s, char *line)
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
	if (s->map.w != 0 && s->map.w != count)
		return (-1);
	return(count);
}

static char	*parse_slab(t_all *s, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (parse_slablen(s, line) + 1))))
		return (0);
	j = 0;
	while (line[*i] != '\0')
	{
		if (ft_strchr("01NSWE", line[*i]))
			slab[j++] = line[*i];
		else if (line[*i] == '2')
		{
			slab[j++] = line[*i];
			s->map.spr++;
		}
		else if (line[*i] != ' ')
			return(slab = ft_free(slab));
		(*i)++;
	}
	slab[j] = '\0';
	return(slab);
}

int		parse_map(t_all *s, char *line, int *i)
{
	char	**tmp;
	int		j;

	s->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (s->map.h + 2))))
		return (MAP_ALLOC_FAIL);
	j = s->map.h + 1;
	while (--j > 0)
		tmp[j] = s->map.tab[j - 1];
	if ((tmp[0] = parse_slab(s, line, i)) == NULL)
	{
		tmp = ft_free(tmp);
		return (MAP_INV);
	}	
	tmp[s->map.h + 1] = NULL;
	if (s->map.h > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.h++;
	if ((s->map.w = parse_slablen(s, line)) == -1)
		return (MAP_SHAPE);
	return (0);
}
