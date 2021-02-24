#include "cub3d.h"

# if 0 
static	char **copy_map(char **map)
{
	char	**map_cpy;
	int		i;
//	int		j;
//
	map_cpy = NULL; 
	i = -1;
//	while (map[++i])
//	{
//		j = -1;
//		while (map[i][++j])
//			map_cpy[i][j] = map[i][j];
//	}
	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
//	printf("%s\n", map[++i]);pd(i);
	return (map_cpy);
}
# endif
int			map_check_open(char **map)
{
	int		ret;

	ret = 0;
	ret = ft_2strlen((char *const *)map);
	pd(ret);
	return (ret);
}
