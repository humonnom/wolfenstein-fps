NAME = cub3D

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
		map_check_iter \
		check_load \
		parse_sprite \
		parse_tools \
		arrange_map

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

GAME =	handle_key \
		error \
		exit_game

SAVE =	save_bitmap \
		make_bitmap_file

GNL =	get_next_line

FIL =	$(addsuffix .c, $(addprefix srcs/, $(SRC))) \
		$(addsuffix .c, $(addprefix srcs/parse/, $(PARSE))) \
		$(addsuffix .c, $(addprefix srcs/draw/, $(DRAW))) \
		$(addsuffix .c, $(addprefix srcs/game/, $(GAME))) \
		$(addsuffix .c, $(addprefix srcs/init/, $(INIT))) \
		$(addsuffix .c, $(addprefix srcs/err/, $(ERR))) \
		$(addsuffix .c, $(addprefix srcs/save/, $(SAVE))) \
		$(addsuffix .c, $(addprefix utils/gnl/, $(GNL)))

OBJ = $(FIL:.c=.o)

INCDIR = incs/

B_SRC = cub3d_bonus

B_INIT =init_info_bonus

B_PARSE =	parse_file_bonus \
			parse_file_post_bonus \
			parse_hand_bonus \
			parse_map_bonus \
			parse_map_part_bonus \
			parse_map_tools_bonus \
			parse_texture_bonus \
			parse_check_bonus \
			map_check_bonus \
			map_check_iter_bonus \
			check_load_bonus \
			parse_sprite_bonus \
			parse_tools_bonus \
			arrange_map_bonus

B_DRAW =	draw_view_bonus \
			draw_background_bonus \
			draw_window_bonus \
			draw_window_col_bonus \
			set_wall_bonus \
			draw_sprite_meta_bonus \
			draw_sprite_bonus \
			draw_sprite_col_bonus \
			set_sprite_bonus \
			turn_on_spr_flag_bonus \
			draw_hand_bonus

B_SKYBOX =	draw_minimap_bonus \
		 	mark_objects_bonus \
		 	mark_user_position_bonus \
		 	mark_direction_bonus \
		 	mark_sprite_bonus \
		 	mark_tools_bonus

B_GAME =	handle_key_bonus \
			error_bonus \
			exit_game_bonus

B_SAVE =	save_bitmap_bonus \
			make_bitmap_file_bonus

B_FIL =	$(addsuffix .c, $(addprefix bonus/, $(B_SRC))) \
		$(addsuffix .c, $(addprefix bonus/parse/, $(B_PARSE))) \
		$(addsuffix .c, $(addprefix bonus/draw/, $(B_DRAW))) \
		$(addsuffix .c, $(addprefix bonus/skybox/, $(B_SKYBOX))) \
		$(addsuffix .c, $(addprefix bonus/game/, $(B_GAME))) \
		$(addsuffix .c, $(addprefix bonus/init/, $(B_INIT))) \
		$(addsuffix .c, $(addprefix bonus/err/, $(B_ERR))) \
		$(addsuffix .c, $(addprefix bonus/save/, $(B_SAVE))) \
		$(addsuffix .c, $(addprefix utils/gnl/, $(GNL)))

B_OBJ = $(B_FIL:.c=.o)

LIBDIR = utils/libft/

MLXDIR = mlx/

LIBOPT = -L./utils/libft -lft

MLXOPT = -L./mlx -lmlx

LXFLAGS = -framework OpenGL -framework Appkit

all: $(NAME)

.c.o:
	@printf "Generating cub3D... %-33.33s\r" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBDIR) all
	@$(MAKE) -C $(MLXDIR) all
	@echo "\033[35m-= Making Cub3D... =-"
	@$(CC) -o $(NAME) $(LIBOPT) $(MLXOPT) $(LXFLAGS) $(OBJ)
	@echo "\033[32m   ______      __   _____ ____  "
	@echo "\033[32m  / ____/_  __/ /_ |__  // __ \ "
	@echo "\033[32m / /   / / / / __ \ /_ </ / / / "
	@echo "\033[32m/ /___/ /_/ / /_/ /__/ / /_/ /  "
	@echo "\033[32m\____/\__,_/_.___/____/_____/   "

clean:
	@rm -rf $(OBJ) $(B_OBJ)
	@rm -f bitmap.bmp
	@$(MAKE) -C $(LIBDIR) clean
	@$(MAKE) -C $(MLXDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBDIR) fclean

bonus: fclean $(B_OBJ)
	@$(MAKE) -C $(LIBDIR) all
	@$(MAKE) -C $(MLXDIR) all
	@echo "\033[35m-= Making Cub3D Bonus... =-"
	@$(CC) -o $(NAME) $(LIBOPT) $(MLXOPT) $(LXFLAGS) $(B_OBJ)
	@echo "\033[32m  __                                         "
	@echo "\033[32m /\ \                                        "
	@echo "\033[32m \ \ \____    ___     ___   __  __    ____   "
	@echo "\033[32m  \ \  __ \  / __ \ /  _  \/\ \/\ \  /  __\  "
	@echo "\033[32m   \ \ \L\ \/\ \L\ \/\ \/\ \ \ \_\ \/\__   \ "
	@echo "\033[32m    \ \____/\ \____/\ \_\ \_\ \____/\/\____/ "
	@echo "\033[32m     \/___/  \/___/  \/_/\/_/\/___/  \/___/  "

	./$(NAME) maps/west.cub

re: fclean all

norm :
	@echo "\033[35m-= Checking norminette all c/h files... =-"
	@norminette incs
	@norminette srcs
	@norminette bonus
	@norminette utils/gnl
	@norminette utils/libft/*.c
	@norminette utils/libft/*.h
		
.PHONY: all clean fclean re bonus norm
