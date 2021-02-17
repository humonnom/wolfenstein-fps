NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =	cub3d \
		init \
		error \
		view \
		view_col \
		wall \
		key \
		minimap \
		minimap_mark \
		sound

PARSE = parse \
		parse_map \
		parse_tex \
		parse_check \
		parse_tools \

GNL =	get_next_line

FIL =	$(addsuffix .c, $(addprefix ./, $(SRC))) \
		$(addsuffix .c, $(addprefix ./, $(PARSE))) \
		$(addsuffix .c, $(addprefix gnl/, $(GNL)))

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
