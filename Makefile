
NAME = cub3d
CC = cc
FLAGS = -Wall -Wextra -Werror
VPATH = srcs/ srcs/init/ srcs/hooks/ srcs/engine/ srcs/utils srcs/engine/raycasting srcs/parse
FLAGS = -Wall -Wextra -Werror -Iinclude -Iminilibx-linux
LFLAGS = -Lminilibx-linux -lmlx -lX11 -lXext -lm -Llibft -lft
LIBFT = libft/libft.a
LIBFT_DIR = libft/

INIT = init_vars init_player init_map init_mlx_window init_texture init_ray_draw
HOOKS =  the_hooks handle_keys_state escape
ENGINE = draw_map draw_cube_player every_frame update_pos floor_ceiling update_pos_rot
RAYCASTING = raycasting casting r_hit_wall r_offset_calc draw_graphics
UTILS = my_mlx_pixel_put line_drawing get_time pixel_display_utils flood_fill_map errors free
PARSE = parse next_gnl parse_init

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

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
