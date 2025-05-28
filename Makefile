
NAME = cub3D
CC = cc
VPATH = srcs/ srcs/init/ srcs/hooks/ srcs/engine/ srcs/utils srcs/engine/raycasting srcs/parse
FLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux -Ilibft -g3
LFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -Llibft -lft
LIBFT = libft/libft.a
LIBFT_DIR = libft/
MLX = minilibx-linux/libmlx.a
MLX_DIR = minilibx-linux/
HDR = include/cub.h

INIT = init_vars init_player init_map init_mlx_window init_texture init_ray_draw
HOOKS =  the_hooks handle_keys_state escape
ENGINE = every_frame update_pos floor_ceiling update_pos_rot 
RAYCASTING = raycasting casting r_hit_wall r_offset_calc draw_graphics
UTILS = get_time pixel_display_utils flood_fill_map lst_to_int_map lst_utils errors free
PARSE = parse next_gnl_utils next_gnl print_error_msg parse_init line_into_texture_pth line_into_colors

SRCS = $(addsuffix .c, $(INIT))\
		$(addsuffix .c, $(HOOKS))\
		$(addsuffix .c, $(ENGINE))\
		$(addsuffix .c, $(RAYCASTING))\
		$(addsuffix .c, $(UTILS))\
		$(addsuffix .c, $(PARSE))\
		main.c
#  echo :
# 	 @echo $(SRCS)

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRCS:%.c=%.o))

#  echo :
# 	  @echo $(OBJ)

$(NAME): $(MLX) $(OBJ) $(LIBFT) 
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)%.o: %.c $(HDR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean $(NAME)
