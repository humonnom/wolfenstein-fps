#include "cub3d.h"
#if 1 
static	t_sprite *get_content(double x, double y)
{
	t_sprite	*ret;

	ret = NULL;
	if ((ret = (t_sprite *)malloc(sizeof(t_sprite))))
	{
		ret->x = x;
		ret->y = y;
		ret->draw_x = 0;
		ret->draw_y = 0;
		ret->dist = 0;
		ret->lh = 0;
		ret->ds = 0;
		ret->de = 0;
	}
	return (ret);
}
#endif
int		parse_sprite(t_info *info)
{
	int			j;
	int			k;
	int			ret;
	t_sprite	*tmp_spr;	

	ret = 0;
	if (info->sprite != NULL)
		ret = SPRITE_DOUBLE;
	j = -1;
	while (ret == 0 && ++j < info->map.h)
	{
		k = -1;
		while (ret == 0 && ++k < info->map.w)
		{
			if (info->map.tab[j][k] == '2')
			{
				if (!(tmp_spr = get_content(k + 0.5, j + 0.5)))
					ret = 1;
				ft_lstadd_back(&info->sprite, ft_lstnew(tmp_spr));	
				info->map.sprite++;
			}
		}
	}	
	return (ret);
}
