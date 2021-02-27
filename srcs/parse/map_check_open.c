#include "cub3d.h"

static char		**init_iter_info(char **map, int *i, int *j)
{
	(*i) = 0;
	(*j) = 0;
	ft_spaceskip(map[0], j);
	if (map[0][(*j)] != '1')
		return (0);
	map[0][(*j)] = 'x';
	return (map);
}
#if 0
static void			print_map(char **map)
{
	int i;

	i = -1;
	while(map[++i])
	{
		ps(map[i]);	
	}
}
#endif

static int			map_check_iter(char **map, int i, int j, int step)
{
	if (map[i][j + step] && map[i][j + step] == 'x')
		return (0);
	if (map[i + step] && map[i + step][j] == 'x')
		return (0);
	if (map[i][j + step] && map[i][j + step] == '1')
	{
		j += step;
		map[i][j] = 'w';
	}
	else if (map[i + step] && map[i + step][j] == '1')
	{
		i += step;
		map[i][j] = 'w';
	}
	else if (step == 1)
		return (map_check_iter(map, i, j, -1));
	else 
		return (1);
	return (map_check_iter(map, i, j, 1));
}

int			map_check_open(char **map)
{
	int		ret;
	char	**map_cpy;
	int		i;
	int		j;

	ret = 0;
	map_cpy = NULL;
	ret = (!(map_cpy = ft_2strdup(map)));
	if (ret == 0)
		ret = (!(map_cpy = init_iter_info(map_cpy, &i, &j)));
	if (ret == 0)
		ret = (map_check_iter(map_cpy, i, j, 1));
	if (map_cpy)
		ft_2strfree(map_cpy);
	return (ret);
}
