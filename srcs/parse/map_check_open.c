#include "cub3d.h"

# if 1 
typedef struct		s_iter
{
	int				start_i;
	int				start_j;
	int				i;
	int				j;
	int				i_step;
	int				j_step;
	int				main_step_flag;
}					t_iter;

static void		init_iter_info(t_iter *iter, char **map)
{
	int j;

	j = 0;
	ft_spaceskip(map[0], &j);
	iter->i = 0;
	iter->j = j + 1;
	map[0][j] = 'x';
}

static void			print_map(char **map)
{
	int i;

	i = -1;
	while(map[++i])
	{
		ps(map[i]);	
	}
}

static int			map_check_iter(t_iter *iter, char **map, int step, char old, char new)
{
	char cur;
	char *next_line;

	cur = map[iter->i][iter->j];
	next_line = map[iter->i + step];
	if (map[iter->i][iter->j + step] && map[iter->i][iter->j + step] == 'x')
		return (0);
	if (map[iter->i + step] && map[iter->i + step][iter->j] == 'x')
		return (0);
	else if (cur == old && map[iter->i][iter->j + step] && map[iter->i][iter->j + step] == old)
	{
		map[iter->i][iter->j] = new;
		print_map(map);
		pd(iter->i);
		pd(iter->j);
		iter->j += step;
	}
	else if (cur == old && map[iter->i + step] && map[iter->i + step][iter->j] == old)
	{
		map[iter->i][iter->j] = new;
		print_map(map);
		pd(iter->i);
		pd(iter->j);
		iter->i += step;
	}
	else if (step == 1)
		return (map_check_iter(iter, map, -1, old, new));
	else if (step == -1 && old == '1')
		return (map_check_iter(iter, map, -1, 'w', 'c'));
	else
		return (1);
	return (map_check_iter(iter, map, step, old, new));
}

# endif

int			map_check_open(char **map)
{
	int		ret;
	char	**map_cpy;
	t_iter	iter;

	ret = 0;
	ret = (!(map_cpy = ft_2strdup(map)));
	init_iter_info(&iter, map_cpy);
	if (map_check_iter(&iter, map_cpy, 1, '1', 'w'))
		ret = 1;
	if (ret == 0)
		ft_2strfree(map_cpy);
	return (ret);
}
