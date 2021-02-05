#ifndef CUB3D_H
# define CUB3D_H

/*------------------FOR TEST ONLY------------------*/
# include <stdio.h>
/*-------------------------------------------------*/

// Library //
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

# include "../mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

// Define //
# define EXIT_BTN 17
# define KEY 2
# define PIXEL_SIZE 64

# define ERR -1
# define DONE 1
# define FILE_OPEN -20
# define FILE_PARSE -2
# define RES_DOUBLE -3
# define RES_INV -4
# define FC_DOUBLE -5
# define FC_INV -6
# define TEX_DOUBLE -7
# define TEX_ALLOC_FAIL -8
# define TEX_INV -9
# define LINE_INV -10
# define MAP_ALLOC_FAIL -11
# define MAP_INV -12
# define MAP_SHAPE -13
# define RES_MISSING -14
# define TEX_MISSING -15
# define FC_MISSING -16
# define POS_MISSING -17
# define POS_DOUBLE -18
# define MAP_CRACK -19
# define MARK_ERR -21
# define ARG_NUM -22
# define MAP_NAME -23
# define SAVE_OPT -24
# define INIT_FAIL -25

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x3CAEFF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPEED 0.1
# define TURN 0.03
# define PLANEX 0.00
# define PLANEY 0.66

//      bonus      //
# define BLOCK_MIN 15
# define BLOCK_MAX 20

//      test        //
# define pf(X) printf(""#X" :%f\n", X)
# define pd(X) printf(""#X" :%d\n", X)
# define pxy(X) printf(""#X" :(%f, %f)\n", (double)s->X.x, (double)s->X.y)

typedef struct  s_spr
{
    double          x;
    double          y;
    double          d;
}               t_spr;

typedef struct		s_wall
{
	unsigned int	*texture_x;
	unsigned int	*texture_y;
	double			wallx;
	double			step;
	double			texpos;
	int				tex_x;
	int				tex_y;
}					t_wall;

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_err
{
	int				n;
	int				m;
	int				p;
}					t_err;

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*adr;
}					t_img;

typedef struct		s_win
{
	void			*ptr;
	int				x;
	int				y;
}					t_win;

typedef struct  s_map
{
    char            **tab; //map 전체저장
    int             w;
    int             h;	//map의 높이
    int             x;
    int             y;
    int             spr;
}               t_map;

typedef struct  s_tex
{
    unsigned int    *n;
    unsigned int    *s;
    unsigned int    *e;
    unsigned int    *w;
    unsigned int    *i;
    unsigned int    c;
    unsigned int    f;
}               t_tex;

typedef struct	s_ray
{
	double			x;
	double			y;
	int				i;
	double			v;
	double			w;
}				t_ray;

typedef struct  s_hit
{
	int			f;
	int			s;
}               t_hit;

typedef struct	s_pos
{
	double			x;
	double			y;
}				t_pos;

typedef struct	s_dir
{
	double			x;
	double			y;
	char			d;
}				t_dir;


typedef struct	s_pla
{
	double			x;
	double			y;

}				t_pla;

typedef struct	s_tim
{
	double			now;
	double			old;
	double			frame;
	double			ms;
	double			rs;
}				t_tim;

typedef struct	s_cmr
{
	double			x;
	double			y;

}				t_cmr;

typedef struct	s_stp
{
	int				x;
	int				y;

}				t_stp;

typedef struct	s_dst
{
	double			sx;
	double			sy;
	double			dx;
	double			dy;
	double			pw;
}				t_dst;

typedef struct	s_scr
{
	int				lh;
	int				ds;
	int				de;
}				t_scr;

typedef struct		s_all
{
	t_mlx			mlx;
	t_err			err;
	t_win			win;
	t_img			img;
	t_tex			tex;
	t_map			map;
	t_ray			ray;
	t_hit			hit;
	t_pos			pos;
	t_dir			dir;
	t_pla			pla;	//plane
	t_tim			tim;	//time
	t_cmr			cmr;	//camera
	t_dst			dst;	//dist
	t_stp			stp;	//step
	t_scr			scr;	//screen
	t_spr			*spr;

}					t_all;

////////////////////bonus////////////////////


typedef struct	s_mini
{
	int	w;
	int	h;
	int xs;
	int	xe;
	int	ys;
	int ye;
	int bsize;
}				t_mini;

typedef struct	s_bonus
{
	t_mini	mini;
}				t_bonus;

/* minimap.c */
void			ft_minimap(t_all *s);
void			ft_initmini(t_bonus b);
void			ft_declaremini(t_all *s, t_bonus *b);
void			ft_drawmini(t_all *s, t_bonus *b);
void			ft_lect(int sort, t_all *s, t_bonus *b);

/* minimap_mark.c*/
int				ft_mark(t_all *s, const t_mini *m);
int				ft_markpos(t_all *s, const t_mini *m);
int				ft_markray(t_all *s, const t_mini *m, int pos);


/*init.c*/
int 			ft_init(t_all *s);
void			ft_init_mlx(t_all *s);
void			ft_init_ray(t_all *s);
void			ft_init_map(t_all *s);
void			ft_init_else(t_all *s);

/*main.c*/
int				main(int argc, char **argv);

/*cub3D.c*/
int				cub3d_loop(t_all s, char *cub, int save);
void			draw_window(t_all *s);


/*error.c*/
int				ft_strerr(int err);
void			ft_printerr(const char *s);

////////////////////// Modified //////////////////////

/*key.c*/
int				ft_close(t_all *s, int win);
int				ft_key(int key, t_all *s);
void			ft_rotate(t_all *s, double c);
void			ft_move(t_all *s, int c);
void			ft_strafe(t_all *s, int c);

/*3dview.c*/
void			get_3d(t_all *s);
void			ft_time(t_all *s);

/*3dview_col.c*/
void			get_3d_col(t_all *s, int x);
void			set_init(t_all *s, int x);
void			set_step(t_all *s);
void			run_dda(t_all *s);
void			set_draw_range(t_all *s);

/*wall.c*/
void			draw_wall(t_all *s, int x);
static void		ft_get_info(t_all *s, t_wall *w);
static void		ft_init_wall(t_wall w);

/*sprite.c*/
void			ft_sprite(t_all *s);
void			ft_sorder(t_all *s);
void			ft_slocate(t_all *s, double dirx, double diry, double dist);
void			ft_sdraw(t_all *s, int loc, double dist);
unsigned int	ft_spixel(t_all *s, int index, unsigned int col);


///*save.c*/
//int				ft_bitmap(t_all *s);
//void			ft_bitdraw(t_all *s);
//void			ft_bitfile(t_all *s, int fd);
//void			ft_bitinfo(t_all *s, int fd);
//void			ft_bitdata(t_all *s, int fd);

/*parse.c*/
int				ft_line(t_all *s, char *line);
int				ft_parse(t_all *s, char *cub);

/*parse_tools.c*/
void			ft_pos(t_all *s);
int				ft_res(t_all *s, char *line, int *i);
int				ft_colors(unsigned int *color, char *line, int *i);
int				ft_slist(t_all *s);

/*parse_check.c*/
int				ft_savecheck(char *arg, char *save);
int				ft_mapcheck(t_all *s);
int				ft_parcheck(t_all *s);

/*parse_map.c*/
int				ft_texture(t_all *s, unsigned int **adr, char *line, int *i);
int				ft_map(t_all *s, char *line, int *i);
char			*ft_slab(t_all *s, char *line, int *i);
int				ft_slablen(t_all *s, char *line);
int				ft_xpm(t_all *s, unsigned int **adr, char *file);

/*has to be deleted*/
#endif
