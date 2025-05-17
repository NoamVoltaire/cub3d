
NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror
VPATH = srcs/ srcs/init/ srcs/hooks/ srcs/engine/ srcs/utils srcs/engine/raycasting srcs/parse
FLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux -Ilibft
LFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -Llibft -lft
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux/

INIT = init_vars init_player init_map init_mlx_window init_texture
HOOKS =  the_hooks handle_keys_state escape
ENGINE = draw_map draw_cube_player every_frame update_pos
RAYCASTING = raycasting casting r_hit_wall r_offset_calc draw_graphics
UTILS = my_mlx_pixel_put line_drawing
PARSE = parse

SRCS = $(addsuffix .c, $(INIT))\
		$(addsuffix .c, $(HOOKS))\
		$(addsuffix .c, $(ENGINE))\
		$(addsuffix .c, $(RAYCASTING))\
		$(addsuffix .c, $(UTILS))\
		main_loop.c\
		main.c
#  echo :
# 	 @echo $(SRCS)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

#  echo :
# 	  @echo $(OBJ)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
