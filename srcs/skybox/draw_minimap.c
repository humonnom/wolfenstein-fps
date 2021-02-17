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

static void	declare_mini(t_all *s, t_bonus *b)
{
	if (s->win.x >= 500 && s->win.y >= 500)
	{	
		b->mini.bsize = ft_min(s->win.x/30, s->win.y/30);
		b->mini.bsize = ft_max(b->mini.bsize, BLOCK_MIN);
		b->mini.bsize = ft_min(b->mini.bsize, BLOCK_MAX);
		b->mini.w = b->mini.bsize * s->map.w;
		b->mini.h = b->mini.bsize * s->map.h;
	}
}

static void	draw_lectangle(int sort, t_all *s, t_bonus *b)
{
	int cur;
	int	end;
	int y_head;
	int x;

	y_head = b->mini.y_head - 1;
	while(++y_head < b->mini.y_tail)
	{
		cur = b->mini.x_head + (s->win.x * y_head);
		end = b->mini.x_tail + (s->win.x * y_head);
		x = cur - 1;
		while(++cur < end)
		{
			if (cur == x || cur == end - 1||\
				y_head == b->mini.y_tail - 1 || y_head == b->mini.y_head)
					s->img.adr[cur] = WHITE ;
			else if (sort == '1')
				s->img.adr[cur] = s->tex.f/2;
			else
				s->img.adr[cur] = BLACK;
		}
	}
}

static void	draw_mini(t_all *s, t_bonus *b)
{
	int		cnt_w;
	int		cnt_h;
	int		tab_h;

	cnt_h = -1;
	while(++cnt_h < s->map.h)
	{
		tab_h = s->map.h - cnt_h - 1;
		cnt_w = -1;
		while (++cnt_w < s->map.w)
		{
			b->mini.y_head = (b->mini.h/s->map.h) * tab_h;
			b->mini.y_tail = b->mini.y_head + b->mini.h/s->map.h;
			b->mini.x_head = (b->mini.w/s->map.w) * cnt_w;
			b->mini.x_tail = b->mini.x_head + b->mini.w/s->map.w;
			draw_lectangle(s->map.tab[cnt_h][cnt_w], s, b);
		}
	}

}

int		draw_minimap(t_all *s)
{
	t_mini	mini;
	t_bonus	b;
	int		ret;
	
	ret = 0;
	init_mini(&mini);
	b.mini = mini;	
	declare_mini(s,&b);
	if (b.mini.w * b.mini.h != 0)
	{
		draw_mini(s, &b);
		ret = mark_objects(s, &b.mini);
	}
	return (ret);
}
