NAME = cub3d

CC = gcc

SRC = main \
	  cub3d \
	  screen \
	  key \
	  tools \
	  parse \
	  parse_map \
	  parse_check \
	  parse_tools \
	  gnl/get_next_line \
	  minimap \
	  mark

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

n: re
	./$(NAME) ../maps/n.cub

w: re
	./$(NAME) ../maps/w.cub

e: re
	./$(NAME) ../maps/e.cub

s: re
	./$(NAME) ../maps/s.cub

save: re
	./$(NAME) ../maps/map.cub --save

lldb: $(OBJ)
	$(CC) -g -o $(NAME) $(LIB_OPT) $(MLX_OPT) $(LXFLAGS) $(OBJ)

.PHONY: all clean fclean re test save
