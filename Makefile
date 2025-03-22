
NAME = cub3d
CC = cc
FLAGS = -Wall -Wextra -Werror
VPATH = srcs/ srcs/init/ srcs/hooks/ srcs/engine/ srcs/utils srcs/engine/raycasting
FLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux
LFLAGS = -Lminilibx-linux -lmlx -framework OpenGL -framework AppKit -lX11 -lXext

INIT = init_vars init_player init_map init_mlx_window
HOOKS =  the_hooks handle_keys_state
ENGINE = draw_map draw_cube_player every_frame update_pos
RAYCASTING = raycasting casting r_hit_wall r_offset_calc
UTILS = my_mlx_pixel_put line_drawing

SRCS = $(addsuffix .c, $(INIT))\
		$(addsuffix .c, $(HOOKS))\
		$(addsuffix .c, $(ENGINE))\
		$(addsuffix .c, $(RAYCASTING))\
		$(addsuffix .c, $(UTILS))\
		main.c
#  echo :
# 	 @echo $(SRCS)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

#  echo :
# 	  @echo $(OBJ)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
