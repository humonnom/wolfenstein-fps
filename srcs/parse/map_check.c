#include "cub3d.h"
static char		**map_check_pre(char **map, int *i, int *j)
{
	(*i) = 0;
	(*j) = 0;
	ft_spaceskip(map[0], j);
	if (map[0][(*j)] != '1')
		return (0);
	map[0][(*j)] = 'w';
	return (map);
}

//static void		print_map(char **map)
//{
//	while (*map)
//		ps(*(map++));
//}
#if 1
static int		map_check_post(char **map, char **map_cpy)
{
	int i;
	int j;
	int ret;

	ret = 0;
	i = -1;
	while (ret == 0 && map[++i])
	{
		j = -1;
		while (ret == 0 && map[i][++j])
			if (map[i][j] == '1' && map_cpy[i][j] != 'w')
				ret = MAP_INV;	
	}
	return (ret);
}
#endif
#if 1

static int			is_valid_range(int i, int j, int max[])
{
	int ret;

	ret = 0;
	if (i >= max[0])
		ret++;
	if (i < 0)
		ret++;
	if (j >= max[1])
		ret++;
	if (j < 0)
		ret++;
	return (!ret);
}

static int			check_load(char **map, int i, int j, int step, int max[])
{
	int count;

	count = 0;
	
	if (is_valid_range(i + step, j, max) && map[i + step] && map[i + step][j] == '1')
		count++;
	if (is_valid_range(i, j + step, max) && map[i] && map[i][j + step] == '1')
		count++;
	step *= -1;
	if (is_valid_range(i + step, j, max) && map[i + step] && map[i + step][j] == '1')
		count++;
	if (is_valid_range(i, j + step, max) && map[i] && map[i][j + step] == '1')
		count++;
	return (count);
}
#endif
static int			map_check_iter(char **map, int i, int j, int step, int max[])
{
	if ((check_load(map, i, j, step, max) == 0))
		return (1);
	else if (is_valid_range(i, j + step, max) && map[i][j + step] && map[i][j + step] == '1')
	{
		j += step;
		map[i][j] = 'w';
	//	print_map(map);
	}
	else if (is_valid_range(i + step, j, max) && map[i + step] && map[i + step][j] == '1')
	{
		i += step;
		map[i][j] = 'w';
	//	print_map(map);
	}
	else if (step == 1)
		return (map_check_iter(map, i, j, -1, max));
	if ((map_check_iter(map, i, j, 1, max)) == 1)
		return (map_check_iter(map, i, j, step, max));
	return (0);
}
#if 0
static int			map_check_iter(char **map, int i, int j, int step)
{
	if (map[i][j + step] && map[i][j + step] == 'x')
	{
		ps("====================================\n");
		return (0);
	}
	else if (map[i + step] && map[i + step][j] == 'x')
	{
		ps("====================================\n");
		return (0);
	}
//	else if (check_load(map, i, j) == 0)
//		return (1);
	else if (map[i][j + step] && map[i][j + step] == '1')
	{
		j += step;
		map[i][j] = 'w';
		print_map(map);
//		if ((map_check_iter(map, i, j, 1) == 1))
//			return (map_check_iter(map, i, j, 1));
	}
	else if (map[i + step] && map[i + step][j] == '1')
	{
		i += step;
		map[i][j] = 'w';
		print_map(map);
//		if ((map_check_iter(map, i, j, 1))== 1)
//			return (map_check_iter(map, i, j, 1));
	}
	else if (step == 1)
		return (map_check_iter(map, i, j, -1));
	else
		return (1);
	return (map_check_iter(map, i, j, step));
}
#endif
int	map_check(t_map *map)
{
	int		ret;
	char	**map_cpy;
	int		i;
	int		j;
	int		max[2];

	ret = 0;
	map_cpy = NULL;
	if (!(map_cpy = ft_2strdup(map->tab)))
		return (1);
	if (ret == 0)
		ret = (!(map_cpy = map_check_pre(map_cpy, &i, &j)));
	if (ret == 0)
	{
		max[0] = map->h;
		max[1] = map->w;
		map_check_iter(map_cpy, i, j, 1, max);
		ret = map_check_post(map->tab, map_cpy);
	}
	ft_2strfree(map_cpy);
	return (ret);
}
