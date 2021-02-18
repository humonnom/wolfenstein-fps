#ifndef CUB3D_H
# define CUB3D_H

/*------------------FOR TEST ONLY------------------*/
/*-------------------------------------------------*/

// Library //
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <signal.h>
# include <stdio.h>
//# include <OpenAL/al.h>
//# include <OpenAL/alc.h>

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
# define VOLUME_UP 126
# define VOLUME_DOWN 125

# define SPEED 0.07
# define TURN 0.04
# define PLANEX 0.00
# define PLANEY 0.66

//      bonus      //
# define BLOCK_MIN 15
# define BLOCK_MAX 20

//      test        //
# define ps(X) printf("%s\n", X)
# define pf(X) printf(""#X" :%f\n", X)
# define pd(X) printf(""#X" :%d\n", X)
# define pxy(X) printf(""#X" :(%f, %f)\n", (double)s->X.x, (double)s->X.y)

typedef struct  s_sprite
{
    double          x;
    double          y;
    double          d;
}               t_sprite;

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
    int             sprite;
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


typedef struct	s_plane
{
	double			x;
	double			y;

}				t_plane;

typedef struct	s_time
{
	double			ms;
	double			rs;
}				t_time;

typedef struct	s_camera
{
	double			x;
	double			y;

}				t_camera;

typedef struct	s_step
{
	int				x;
	int				y;

}				t_step;

typedef struct	s_dist
{
	double			sx;
	double			sy;
	double			dx;
	double			dy;
	double			pw;
}				t_dist;

typedef struct	s_screen
{
	int				lh;
	int				ds;
	int				de;
}				t_screen;

typedef struct		s_all
{
	pid_t			pid;
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
	t_time			time;	//time
	t_plane			plane;	//plane
	t_camera		camera;	//camera
	t_dist			dist;	//dist
	t_step			step;	//step
	t_screen		screen;	//screen
	t_sprite		*sprite;

}					t_all;

////////////////////bonus////////////////////


typedef struct	s_mini
{
	int	w;
	int	h;
	int x_head;
	int	x_tail;
	int	y_head;
	int y_tail;
	int bsize;
}				t_mini;

typedef struct	s_bonus
{
	t_mini	mini;
}				t_bonus;


//=====================/*meta*/==========================
/*cub3D.c*/
int				main(int argc, char **argv);
int				cub3d_loop(t_all s, char *cub, int save);

/*init_all.c*/
int 			init_all(t_all *s);

/*error.c*/
int				err_filter(int err);

//=====================/*view*/==========================
/*view.c*/
void			draw_window(t_all *s);

/*view_col.c*/
void			draw_window_col(t_all *s, int x);

//=====================/*parse*/==========================
/*parse.c*/
int				parse_file(t_all *s, char *cub);

/*parse_check.c*/
int				parse_check(t_all *s);

/*parse_map.c*/
int				parse_map(t_all *s, char *line, int *i);

/*parse_tex.c*/
int				parse_texture(
				t_all *s,
				unsigned int **adr,
				char *line, int *i);


/*parse_tools.c*/
void			parse_pos(t_all *s);
void			parse_plane(t_all *s);
int				parse_resolution(t_all *s, char *line, int *i);
int				parse_colors(unsigned int *color, char *line, int *i);
int				parse_sprite(t_all *s);

//=====================/* minimap */==========================
/* minimap.c */
int				draw_minimap(t_all *s);

//mark_obj
int				mark_objects(t_all *s, const t_mini *m);

int				mark_sprite(t_all *s, const t_mini *m);
int				mark_user_position(t_all *s, const t_mini *m);
void			mark_direction(t_all *s, const t_mini *m, int pos);

//tools
void			draw_circle(t_all *s, int pos, int color);
int				get_position(t_pos pos, int bsize, int win_x, int map_h);

//=====================/*wall.c*/==========================
void			set_wall(t_all *s, int x);

//=====================/*key.c*/==========================
int				get_key(int key, t_all *s);
int				exit_game(t_all *s, int win);


//=====================/*sound.c*/==========================
int				run_sound();
void			handle_sound(int step);

//====================/*handle sprite*/=======================
int				handle_sprite(t_all *s);

#endif
