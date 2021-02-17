#include "cub3d.h"

static void	init_mini(t_mini *mini)
{
	mini->w = 0;
	mini->h = 0;
	mini->xs = 0;
	mini->xe = 0;
	mini->ys = 0;
	mini->ye = 0;
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
	int ys;
	int x;

	ys = b->mini.ys - 1;
	while(++ys < b->mini.ye)
	{
		cur = b->mini.xs + (s->win.x * ys);
		end = b->mini.xe + (s->win.x * ys);
		x = cur - 1;
		while(++cur < end)
		{
			if (cur == x || cur == end - 1||\
				ys == b->mini.ye - 1 || ys == b->mini.ys)
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
			b->mini.ys = (b->mini.h/s->map.h) * tab_h;
			b->mini.ye = b->mini.ys + b->mini.h/s->map.h;
			b->mini.xs = (b->mini.w/s->map.w) * cnt_w;
			b->mini.xe = b->mini.xs + b->mini.w/s->map.w;
			draw_lectangle(s->map.tab[cnt_h][cnt_w], s, b);
		}
	}

}

void	draw_minimap(t_all *s)
{
	t_mini	mini;
	t_bonus	b;

	init_mini(&mini);
	b.mini = mini;	
	declare_mini(s,&b);
	if (b.mini.w * b.mini.h == 0)
		return ;
	draw_mini(s, &b);
	mark_position(s, &b.mini);
}
