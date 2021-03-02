#include "cub3d.h"

static void	init_mini(t_mini *mini)
{
	mini->w = 0;
	mini->h = 0;
	mini->x_head = 0;
	mini->x_tail = 0;
	mini->y_head = 0;
	mini->y_tail = 0;
	mini->bsize = 0;
}

static void	declare_mini(t_info *info, t_bonus *bonus)
{
	if (info->win.x >= 500 && info->win.y >= 500)
	{	
		bonus->mini.bsize = ft_min(info->win.x/30, info->win.y/30);
		bonus->mini.bsize = ft_max(bonus->mini.bsize, BLOCK_MIN);
		bonus->mini.bsize = ft_min(bonus->mini.bsize, BLOCK_MAX);
		bonus->mini.w = bonus->mini.bsize * info->map.w;
		bonus->mini.h = bonus->mini.bsize * info->map.h;
	}
}

static void	draw_lectangle(char sort, t_info *info, t_bonus *bonus)
{
	int cur;
	int	end;
	int y_head;
	int x;

	y_head = bonus->mini.y_head - 1;
	while(++y_head < bonus->mini.y_tail)
	{
		cur = bonus->mini.x_head + (info->win.x * y_head) - 1;
		end = bonus->mini.x_tail + (info->win.x * y_head);
		x = cur - 1;
		while(++cur < end)
		{
			if (cur == x)
				info->img.adr[cur] =  BLACK;
			else if (cur == end - 1)
				info->img.adr[cur] =  BLACK;
			else if (y_head == bonus->mini.y_tail - 1)
				info->img.adr[cur] =  BLACK;
			else if (y_head == bonus->mini.y_head)
				info->img.adr[cur] =  BLACK;
			else if (sort == '1')
				info->img.adr[cur] = LIGHT_BLUE_GREY ;
			else if (ft_strchr("EWSN20", sort))
				info->img.adr[cur] = WHITE;
		}
	}
}

static void	draw_map(t_info *info, t_bonus *bonus)
{
	int		cnt_w;
	int		cnt_h;
	int		tab_h;

	cnt_h = -1;
	while(++cnt_h < info->map.h)
	{
		tab_h = info->map.h - cnt_h - 1;
		cnt_w = -1;
		while (++cnt_w < info->map.w)
		{
			bonus->mini.y_head = (bonus->mini.h/info->map.h) * tab_h;
			bonus->mini.y_tail = bonus->mini.y_head + bonus->mini.h/info->map.h;
			bonus->mini.x_head = (bonus->mini.w/info->map.w) * cnt_w;
			bonus->mini.x_tail = bonus->mini.x_head + bonus->mini.w/info->map.w;
			draw_lectangle(info->map.tab[cnt_h][cnt_w], info, bonus);
		}
	}

}

int		draw_minimap(t_info *info)
{
	t_mini	mini;
	t_bonus	bonus;
	int		ret;
	
	ret = 0;
	init_mini(&mini);
	bonus.mini = mini;	
	declare_mini(info,&bonus);
	if (bonus.mini.w > 0 && bonus.mini.h > 0 && bonus.mini.w < info->win.x && bonus.mini.h < info->win.y)
	{
		draw_map(info, &bonus);
		ret = mark_objects(info, &bonus.mini);
	}
	return (ret);
}
