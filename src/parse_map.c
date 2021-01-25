#include "cub3d.h"

int		ft_xpm(t_all *s, unsigned int **adr, char *file)
{
	int		fd;
	void	*img;
	int		tab[5];

	if (ft_strncmp_reverse(file, ".xpm", 4))
		return (ERR);
	if ((fd = open(file, O_RDONLY)) == ERR)
		return (ERR);
	close(fd);
	img = mlx_xpm_file_to_image(s->mlx.ptr, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (ERR);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	img = ft_free(img);
	return (0);
}

int		ft_texture(t_all *s, unsigned int **adr, char *line, int *i)
{
	char	*file;
	int		get;

	get = 0;
	if (*adr != NULL)
		return (TEX_DOUBLE);
	(*i) += 2;
	ft_spaceskip(line, i);
	if (!(file = ft_strdup(&line[*i])))
		return (TEX_ALLOC_FAIL);
	(*i) += ft_strlen(file);
	get = ft_xpm(s, adr, file);
	file = ft_free(file);
	return ( get == ERR ? TEX_INV : 0);
}

int		ft_map(t_all *s, char *line, int *i)
{
	char	**tmp;
	int		j;


	s->err.m = 1;
	if (!(tmp = malloc(sizeof(char *) * (s->map.y + 2))))
		return (MAP_ALLOC_FAIL);
	j = -1;
	while (++j < s->map.y)
		tmp[j] = s->map.tab[j];
	if ((tmp[s->map.y] = ft_slab(s, line, i)) == NULL)
	{
		tmp = ft_free(tmp);
		return (MAP_INV);
	}	
	tmp[s->map.y + 1] = NULL;
	if (s->map.y > 0)
		free(s->map.tab);
	s->map.tab = tmp;
	s->map.y++;
	if ((s->map.x = ft_slablen(s, line)) == -1)
		return (MAP_SHAPE);
	return (0);
}

char	*ft_slab(t_all *s, char *line, int *i)
{
	char	*slab;
	int		j;

	if (!(slab = malloc(sizeof(char) * (ft_slablen(s, line) + 1))))
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

int		ft_slablen(t_all *s, char *line)
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
	if (s->map.x != 0 && s->map.x != count)
		return (-1);
	return(count);
}
