NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	cub3d

INIT =	init_all


PARSE = parse_file \
		parse_map \
		parse_texture \
		parse_check \
		parse_tools \

GNL =	get_next_line

DRAW =	draw_window \
		draw_window_col \
		set_wall

SKYBOX = draw_minimap \
		 mark_position \
		 mark_direction \
		 mark_sprite \
		 mark_objects

SOUND =	sound

GAME =	key \
		error \
		exit_game

FIL =	$(addsuffix .c, $(addprefix ./, $(SRC))) \
		$(addsuffix .c, $(addprefix parse/, $(PARSE))) \
		$(addsuffix .c, $(addprefix gnl/, $(GNL))) \
		$(addsuffix .c, $(addprefix draw/, $(DRAW))) \
		$(addsuffix .c, $(addprefix skybox/, $(SKYBOX))) \
		$(addsuffix .c, $(addprefix sound/, $(SOUND))) \
		$(addsuffix .c, $(addprefix game/, $(GAME))) \
		$(addsuffix .c, $(addprefix init/, $(INIT))) \
		$(addsuffix .c, $(addprefix err/, $(ERR)))

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
