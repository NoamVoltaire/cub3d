/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:55 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:33:06 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <X11/X.h> 
# include <stdbool.h>
# include <string.h>
# include <math.h>
#include <sys/time.h>

//# define HEIGHT 1880
# define HEIGHT 940
//# define WIDTH 2540
# define WIDTH 1270
# define PI 3.141592653589793//23846
# define tPI 6.28318530718
# define PII 1.57079632679
# define PIII 4.71238898038
# define DR 0.0174533

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
// #include <time.h>
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

}		t_vars;

void	init_vars(t_vars *vars);
void	init_map(t_map *map);
void	init_player(t_player *player);
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
void	update_pos(t_player *player, t_map *map);
void	draw_rays(t_player *player, t_map *map, t_vars *vars);
int		draw_cube_player(t_player player, t_vars *vars);

//RAYCASTING
t_ray	casting(t_player *player, t_map *map, t_vars *vars, double ra);
void	r_offset_calc_x(t_ray *ray, t_map *map, t_player *player, double ra);
void	r_offset_calc_y(t_ray *ray, t_map *map, t_player *player, double ra);
float	r_hit_wall(t_ray *ray, t_map *map, t_vars *vars);

void	draw_graphics(t_ray *ray, int ray_nb, t_vars *vars);

void	draw_floor_ceiling(t_vars *vars, char *floor, char *ceiling);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	line_drawing(t_vars *vars, int x0, int y0, int x1, int y1);

#endif
