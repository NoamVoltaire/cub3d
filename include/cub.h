/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:55 by noam              #+#    #+#             */
/*   Updated: 2025/05/28 10:00:01 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define BUFFER_SIZE 42
# define FD_MAX 1024
# define GNL_SUCCESS 0
# define GNL_EOF 1
# define GNL_ESYS -1
# define GNL_ERANGE -2

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <X11/X.h> 
# include <stdbool.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include "error.h"
# include "libft.h"

//# define HEIGHT 1880
# define HEIGHT 940
//# define WIDTH 2540
# define WIDTH 1280
# define TILE_SIZE 64  
# define PI 3.141592653589793//23846
# define tPI 6.28318530718
# define PII 1.57079632679
# define PIII 4.71238898038
# define DR 0.0174533

typedef struct s_gnl
{
	char	*save;
	char	*tmp_save;
	char	**line;
	int		fd;
}	t_gnl;

typedef struct s_parse
{
	int	**tab;
	int	m_w;
	int	m_h;
	int	p_first_xposm;
	int	p_first_yposm;
	double	playerxpos;
	double	playerypos;
	double	p_angle;
	char	*t_paths[4];
	int f_color_input[4];
	int c_color_input[4];
	int	m_has_player;
	t_list	*lines;
}	t_parse;

typedef	struct s_tex
{
	void	*img;
	char	*addr;
	int		w;
	int		h;

}	t_tex;

typedef	struct s_textures
{
//	void	*no_texture;
//	void	*so_texture;
//	void	*we_texture;
//	void	*ea_texture;
//	char	*t_addr_no;
//	char	*t_addr_so;
//	char	*t_addr_we;
//	char	*t_addr_ea;

	t_tex	no;
	t_tex	so;
	t_tex	we;
	t_tex	ea;
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct s_raydraw
{
	float	t_y_step;
	float	t_x_step;
	float	y_uv;
	float	x_uv;
	int		t_y;
	int		l_height;
	int		y;
}	t_raydraw;

typedef struct s_ray
{
	t_raydraw	render;
	double		ra;
	double		rx;
	double		ry;
	double		xo;
	double		yo;
	int			hit_data;
	int			hit_dir;
	float		hit_len;
}		t_ray;

typedef struct s_map
{
	int		**grid;
	int		tilesize;
	int		mapx;
	int		mapy;
}		t_map;

typedef struct s_keyb
{
	bool	forwards;
	bool	backwards;
	bool	left;
	bool	right;
	bool	see_left;
	bool	see_right;

}		t_keyb;

typedef struct s_player
{
	t_keyb	keybind;
	double	xpos;
	double	ypos;
	double	xdelt;
	double	ydelt;
	double	angle;
	double	last_frame;
	double	delta_time;
	float	move_spd;
	float	rot_spd;

}		t_player;

typedef struct s_moveprobe
{
	float	xo;
	float	yo;
	int		mpx;
	int		mpy;
	int		pos_xo;
	int		pos_yo;
}	t_moveprobe;


typedef struct s_vars
{
	void		*mlx;
	void		*window;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		map;
	t_player	player;
	t_texture	textures;
	t_parse		parse;
	t_list	*lst;

}		t_vars;


//PARSING
int            print_error_msg(char *msg);
int            parse_into_vars(int fd, t_vars *vars);
int		initialize_gnl_data(t_gnl *data, char *save, char **line, int fd);
int		get_save(t_gnl *data);
int		get_line(t_gnl *data);
int            next_gnl(char **line, int fd);
bool	is_map_line(char *line);

void	init_f_c_parse(t_list *lines, t_parse *parse);
void	init_t_parse(t_list *lines, t_parse *parse);


void	initialize_vars(t_list *lst, t_parse *parse);

int	**lst_to_int_map(t_list *lst, t_parse *parse);
size_t	longest_row(t_list *lst);
t_list	*skip_to_map_lines(t_list *lst);
int	**allocate_map_array(size_t rows, size_t cols);
//int	process_map_line(char *line, int *row, int row_idx, t_parse *parse);
//int	check_args_before_map(t_list *lines);


int	line_into_texture_path(char *line, t_parse *parse, int j);
int	line_into_color_textures(t_parse *parse, char *line, int j);


void	init_vars(t_vars *vars);
//void	init_map(t_map *map);
void	init_map(t_map *map, t_parse *parse);
void	init_player(t_player *player, t_parse *parse);
void	init_window(t_vars *vars);
void	init_textures(t_vars *vars, int floor_col, int ceiling_col);
void	the_hooks(t_vars *vars);
int close_window(t_vars *vars);
int		handle_key_press(int keycode, t_vars *vars);
int		handle_key_release(int keycode, t_vars *vars);
int	escape(int keycode,t_vars *vars);
int		every_frame(void *param);

void	draw_map(t_map map, t_vars *vars);
double	get_time(void);
int	flood_fill_map(t_parse *parse,int x, int y);

void	update_pos(t_player *player, t_map *map);
void	handle_rotation(t_player *player);
void	move_strafe_left(t_player *player, t_map *map);
void	move_strafe_right(t_player *player, t_map *map);

void	draw_rays(t_player *player, t_map *map, t_vars *vars);
int		draw_cube_player(t_player player, t_vars *vars);

//RAYCASTING
t_ray	casting(t_player *player, t_map *map, t_vars *vars, double ra);
void	r_offset_calc_x(t_ray *ray, t_map *map, t_player *player, double ra);
void	r_offset_calc_y(t_ray *ray, t_map *map, t_player *player, double ra);
float	r_hit_wall(t_ray *ray, t_map *map, t_vars *vars);

void	draw_graphics(t_ray *ray, int ray_nb, t_vars *vars);

t_raydraw	init_ray_draw_data(int l_height, t_tex *tex);
t_tex	get_texture_addr(t_ray *ray, t_vars *vars);
unsigned int	darken_color(unsigned int color, int dir);

void	draw_floor_ceiling(t_vars *vars, char *floor, char *ceiling);

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	line_drawing(t_vars *vars, int x0, int y0, int x1, int y1);



void	free_parse(t_parse *parse);
void	handle_parse_error(t_parse *parse, int err_code);


#endif
