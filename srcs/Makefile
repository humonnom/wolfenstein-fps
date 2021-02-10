NAME = cub3d

CC = gcc

SRC =	cub3d \
		init \
		error \
		view \
		view_col \
		wall \
		key \
		parse \
		parse_map \
		parse_tex \
		parse_check \
		parse_tools \
		minimap \
		minimap_mark \
		sound \
		gnl/get_next_line


FIL = $(addsuffix .c, $(addprefix ./, $(SRC)))

OBJ = $(FIL:.c=.o)

LIB_DIR = ./libft

LIB_OPT = -L./libft -lft

MLX_OPT = -L../mlx -lmlx

LXFLAGS = -framework OpenGL -framework Appkit

all: $(NAME) 

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_DIR) all
	@$(CC) -o $(NAME) $(LIB_OPT) $(MLX_OPT) $(LXFLAGS) $(OBJ)

clean:
	@rm -rf $(OBJ)
	@rm -f bitmap.bmp
	@$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIB_DIR) fclean

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
	@$(CC) -g -o $(NAME) $(LIB_OPT) $(MLX_OPT) $(LXFLAGS) $(OBJ)

.PHONY: all clean fclean re test n w e s save lldb
