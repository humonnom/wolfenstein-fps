#ifndef CUB3D_H
# define CUB3D_H


/*
** Library
*/

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>
# include <signal.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

/********
** define 
********/

/*
** minimap 
*/

# define EXIT_BTN 17
# define KEY 2
# define PIXEL_SIZE 64

# define PRINT 1
# define NON_PRINT 0

# define FLOOR 1
# define CEILING 0

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
# define SPRITE_DOUBLE -26

# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define GREY 0x00A9A9A9
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x3CAEFF
# define DARK_BLUE 0x002F4F4F
# define LIGHT_BLUE_GREY 0x00778899
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

/*
** minimap 
*/

# define BLOCK_MIN 15
# define BLOCK_MAX 20

//      test        //
# define ps(X) printf("%s\n", X)
# define pf(X) printf(""#X" :%f\n", X)
# define pd(X) printf(""#X" :%d\n", X)
# define pxy(X) printf(""#X" :(%f, %f)\n", (double)info->X.x, (double)info->X.y)

typedef struct  s_sprite
{
    double          x;
    double          y;
    double          coef_x;
    double          coef_y;
	double			dist_x;
	double			dist_y;
	double			draw_start;
	double			draw_end;
	double			center;
	double		 	depth_unit;
	double			dist;
	double			side_len;
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
	int				space;
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
	double			i;
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

typedef struct		s_info
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
	t_time			time;
	t_plane			plane;
	t_camera		camera;
	t_dist			dist;
	t_step			step;
	t_screen		screen;
	t_list			*sprite;

}					t_info;

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

int				main(int argc, char **argv);

int				cub3d_loop(t_info info, char *cub, int save);

void 			init_info(t_info *info);

int				report_err(int err);

void			draw_view(t_info *info, int print);

void			draw_background(t_info *info);

void			draw_window(t_info *info);

void			draw_window_col(t_info *info, int x);

void			draw_sprite_meta(t_info *info);

void			draw_sprite(
				t_info *info,
				t_sprite *sprite);

void			draw_sprite_col(
				t_info *info,
				t_sprite *sprite, 
				int x);
/*
** parse
*/

int				parse_file(t_info *info, char *cub);

int				parse_file_post(t_info *info);

int				parse_check(t_info *info);

int				map_check(t_map *map);

int				parse_map(t_info *info, char *line);

char			*parse_map_part(t_info *info, char *line);

int				parse_texture(
				t_info *info,
				unsigned int **adr,
				char *line, int *i);

int				arrange_map(int max_width, char **map);

void			parse_pos(t_info *info);

void			parse_plane(t_info *info);

int				parse_resolution(t_info *info, char *line, int *i);

int				parse_colors(unsigned int *color, char *line, int *i);

int				parse_sprite(t_info *info);

/*
** minimap
*/

int				draw_minimap(t_info *info);

int				mark_objects(t_info *info, const t_mini *m);

int				mark_sprite(t_info *info, const t_mini *m);

int				mark_user_position(t_info *info, const t_mini *m);

void			mark_direction(t_info *info, const t_mini *m, int pos);

void		mark_coef(t_info *info, const t_mini *m, int pos, t_list *s);

/*
** tools
*/

void			draw_rect(
				t_info *info,
				int poinfo,
				int color,
				int	width);

int				get_position(
				t_pos pos,
				int bsize,
				int win_x,
				int map_h);

void			set_wall(t_info *info, int x);

void			set_sprite(t_info *info, t_sprite *sprite);


/*
** game
*/

int				get_key(int key, t_info *info);

int				exit_game(t_info *info, int win);


/*
** sprite
*/

int				handle_sprite(t_info *info);

/*
** save 
*/

int				save_bitmap(t_info *info);

int				make_bitmap_file(t_info *info);

#endif
