NAME = cub3d

CC = gcc

SRC = main \
	  cub3d \
	  sprite \
	  screen \
	  screen_col \
	  key \
	  tools \
	  parse \
	  parse_map \
	  parse_check \
	  parse_tools \
	  save_mode \
	  gnl/get_next_line \
	  minimap

FIL = $(addsuffix .c, $(addprefix ./, $(SRC)))

OBJ = $(FIL:.c=.o)

LIB_OPT = -L./libft -lft

MLX_OPT = -L../mlx -lmlx

LXFLAGS = -framework OpenGL -framework Appkit


all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(LIB_OPT) $(MLX_OPT) $(LXFLAGS) $(OBJ)

clean:
	rm -rf $(OBJ)
	rm -f bitmap.bmp

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	./$(NAME) ../maps/map.cub

save: re
	./$(NAME) ../maps/map.cub --save

.PHONY: all clean fclean re test save
