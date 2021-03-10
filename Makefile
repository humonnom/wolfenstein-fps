NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = cub3d

INIT =	init_info

PARSE = parse_file \
		parse_file_post \
		parse_hand \
		parse_map \
		parse_map_part \
		parse_map_tools \
		parse_texture \
		parse_check \
		map_check \
		parse_sprite \
		parse_tools \
		arrange_map

GNL =	get_next_line

DRAW =	draw_view \
		draw_background \
		draw_window \
		draw_window_col \
		set_wall \
		draw_sprite_meta \
		draw_sprite \
		draw_sprite_col \
		set_sprite \
		turn_on_spr_flag \
		draw_hand

SKYBOX = draw_minimap \
		 mark_objects \
		 mark_user_position \
		 mark_direction \
		 mark_sprite \
		 mark_coef \
		 mark_tools

GAME =	handle_key \
		error \
		exit_game

SAVE =	save_bitmap \
		make_bitmap_file

FIL =	$(addsuffix .c, $(addprefix srcs/, $(SRC))) \
		$(addsuffix .c, $(addprefix srcs/parse/, $(PARSE))) \
		$(addsuffix .c, $(addprefix srcs/gnl/, $(GNL))) \
		$(addsuffix .c, $(addprefix srcs/draw/, $(DRAW))) \
		$(addsuffix .c, $(addprefix srcs/skybox/, $(SKYBOX))) \
		$(addsuffix .c, $(addprefix srcs/game/, $(GAME))) \
		$(addsuffix .c, $(addprefix srcs/init/, $(INIT))) \
		$(addsuffix .c, $(addprefix srcs/err/, $(ERR))) \
		$(addsuffix .c, $(addprefix srcs/save/, $(SAVE)))

OBJ = $(FIL:.c=.o)

LIBDIR = srcs/libft/

INCDIR = srcs/

LIBOPT = -L./srcs/libft -lft

MLXOPT = -L./mlx -lmlx

LXFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBDIR) all
	@$(CC) -o $(NAME) $(LIBOPT) $(MLXOPT) $(LXFLAGS) $(OBJ)

clean:
	@rm -rf $(OBJ)
	@rm -f bitmap.bmp
	@$(MAKE) -C $(LIBDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
