NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	cub3d

INIT =	init_info


PARSE = parse_file \
		parse_file_post \
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
		draw_sprite_meta \
		draw_sprite \
		draw_sprite_col \
		set_sprite \
		set_wall

SKYBOX = draw_minimap \
		 mark_objects \
		 mark_user_position \
		 mark_direction \
		 mark_sprite \
		 mark_tools

SOUND =	sound

GAME =	handle_key \
		error \
		exit_game

SAVE =	save_bitmap \
		make_bitmap_file

FIL =	$(addsuffix .c, $(addprefix ./, $(SRC))) \
		$(addsuffix .c, $(addprefix parse/, $(PARSE))) \
		$(addsuffix .c, $(addprefix gnl/, $(GNL))) \
		$(addsuffix .c, $(addprefix draw/, $(DRAW))) \
		$(addsuffix .c, $(addprefix skybox/, $(SKYBOX))) \
		$(addsuffix .c, $(addprefix sound/, $(SOUND))) \
		$(addsuffix .c, $(addprefix game/, $(GAME))) \
		$(addsuffix .c, $(addprefix init/, $(INIT))) \
		$(addsuffix .c, $(addprefix err/, $(ERR))) \
		$(addsuffix .c, $(addprefix save/, $(SAVE)))

OBJ = $(FIL:.c=.o)

LIBDIR = ./libft

INCDIR = ./

LIBOPT = -L./libft -lft

MLXOPT = -L../mlx -lmlx

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

test: re
	@./$(NAME) ../maps/map.cub

n: re
	@./$(NAME) ../maps/n.cub

w: re
	@./$(NAME) ../maps/w.cub

e: re
	@./$(NAME) ../maps/e.cub

s: re
	@./$(NAME) ../maps/s.cub

save: re
	@./$(NAME) ../maps/map.cub --save

lldb: $(OBJ)
	@$(CC) -g -o $(NAME) $(LIBOPT) $(MLXOPT) $(LXFLAGS) $(OBJ)

.PHONY: all clean fclean re test n w e s save lldb
