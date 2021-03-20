/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juepark <juepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 22:35:05 by juepark           #+#    #+#             */
/*   Updated: 2021/03/20 12:07:22 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

/*
** Library
*/

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>

# include "../mlx/mlx.h"
# include "../utils/libft/libft.h"
# include "../utils/gnl/get_next_line.h"

/*
** define
*/

# define EXIT_BTN 17
# define KEY 2
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define PIXEL_SIZE 64

# define IMAC_X 1680
# define IMAC_Y 1050
# define MAC_X 1680
# define MAC_Y 1050

/*
** error
*/

# define ERR -1
# define FILE_OPEN -2
# define FILE_PARSE -3
# define RES_DOUBLE -4
# define RES_INV -5
# define FC_DOUBLE -6
# define FC_INV -7
# define TEX_DOUBLE -8
# define TEX_ALLOC_FAIL -9
# define TEX_INV -10
# define LINE_INV -11
# define MAP_ALLOC_FAIL -12
# define MAP_INV -13
# define MAP_SHAPE -14
# define RES_MISSING -15
# define TEX_MISSING -16
# define FC_MISSING -17
# define POS_MISSING -18
# define POS_DOUBLE -19
# define MAP_CRACK -20
# define MARK_ERR -21
# define ARG_NUM -22
# define MAP_NAME -23
# define SAVE_OPT -24
# define INIT_FAIL -25
# define SPRITE_DOUBLE -26

/*
** color
*/

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

/*
** key
*/

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

/*
** preset for game
*/

# define SPEED 0.12
# define TURN 0.06

# define PLANEX 0.00
# define PLANEY 0.66

# define BLOCK_MIN 15
# define BLOCK_MAX 20

# define PRINT 1
# define NON_PRINT 0

# define FLOOR 1
# define CEILING 0

typedef struct		s_sprite
{
	double			x;
	double			y;
	double			coef_x;
	double			coef_y;
	double			dist_x;
	double			dist_y;
	double			draw_start;
	double			draw_end;
	double			center_x;
	double			depth_unit;
	double			dist;
	double			side_len;
	double			tex_scale;
	double			tex_step;
	int				visible;
	int				crushed;
}					t_sprite;

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

typedef struct		s_map
{
	char			**tab;
	int				w;
	int				h;
	int				x;
	int				y;
	int				sprite;
	int				space;
}					t_map;

typedef struct		s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*e;
	unsigned int	*w;
	unsigned int	*i;
	unsigned int	*h;
	unsigned int	c;
	unsigned int	f;
}					t_tex;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			i;
	double			v;
	double			w;
}					t_ray;

typedef struct		s_hit
{
	int				f;
	int				s;
}					t_hit;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_dir
{
	double			x;
	double			y;
	char			d;
}					t_dir;

typedef struct		s_plane
{
	double			x;
	double			y;

}					t_plane;

typedef struct		s_time
{
	double			ms;
	double			rs;
}					t_time;

typedef struct		s_camera
{
	double			x;
	double			y;

}					t_camera;

typedef struct		s_step
{
	int				x;
	int				y;

}					t_step;

typedef struct		s_dist
{
	double			sx;
	double			sy;
	double			dx;
	double			dy;
	double			pw;
}					t_dist;

typedef struct		s_screen
{
	int				lh;
	int				ds;
	int				de;
}					t_screen;

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
	double			*zbuf;
}					t_info;

typedef struct		s_mini
{
	int				w;
	int				h;
	int				x_head;
	int				x_tail;
	int				y_head;
	int				y_tail;
	int				bsize;
}					t_mini;

typedef struct		s_bonus
{
	t_mini			mini;
}					t_bonus;

/*
** general
*/

int					main(int argc, char **argv);

int					cub3d_loop(
					t_info info,
					char *cub,
					int save);

void				init_info(t_info *info);

int					report_err(int err);

/*
** draw
*/

void				draw_view(t_info *info, int print);

void				draw_background(t_info *info);

void				draw_window(t_info *info);

void				draw_window_col(t_info *info, int x);

void				draw_sprite_meta(t_info *info);

int					draw_sprite(
					t_info *info,
					t_sprite *sprite);

void				draw_sprite_col(
					t_info *info,
					t_sprite *sprite,
					int x,
					int	spr_x);

void				draw_hand(
					t_info *info);

/*
** parse
*/

int					parse_file(t_info *info, char *cub);

int					parse_file_post(t_info *info);

int					parse_check(t_info *info);

int					map_check(t_map *map);

int					map_check_iter(
					char **map,
					int i,
					int j,
					int max[]);

int					check_load(
					char **map,
					int i,
					int j,
					int max[]);

int					is_valid_range(
					int i,
					int j,
					int max[]);


void				parse_hand(t_info *info);

int					parse_map(t_info *info, char *line);

char				*parse_map_part(t_info *info, char *line);

int					parse_texture(
					t_info *info,
					unsigned int **adr,
					char *line, int *i);

int					arrange_map(int max_width, char **map);

void				parse_pos(t_info *info);

void				parse_plane(t_info *info);

int					parse_resolution(
					t_info *info,
					char *line,
					int *i);

int					parse_colors(
					unsigned int *color,
					char *line,
					int *i);

int					parse_sprite(t_info *info);

t_sprite			*get_content(double x, double y);

/*
** minimap
*/

int					draw_minimap(t_info *info);

int					mark_objects(t_info *info, const t_mini *m);

int					mark_sprite(t_info *info, const t_mini *m);

int					mark_user_position(t_info *info, const t_mini *m);

void				mark_direction(
					t_info *info,
					const t_mini *m,
					int pos);

/*
** tools
*/

void				draw_rect(
					t_info *info,
					int poinfo,
					int color,
					int	width);

int					get_position(
					t_pos pos,
					int bsize,
					int win_x,
					int map_h);

void				set_wall(t_info *info, int x);

/*
** game
*/

int					get_key(int key, t_info *info);

int					exit_game(t_info *info, int win);

/*
** sprite
*/

void				set_sprite(t_info *info);

void				get_set(t_info *info, t_sprite *sprite);

int					handle_sprite(t_info *info);

void				turn_on_spr_flag(
					int x,
					int y,
					t_list *spr_list);

/*
** save
*/

int					save_bitmap(t_info *info);

int					make_bitmap_file(t_info *info);

#endif
