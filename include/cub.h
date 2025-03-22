/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:55 by noam              #+#    #+#             */
/*   Updated: 2025/03/21 17:20:19 by noam             ###   ########.fr       */
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
# define HEIGHT 1280
# define WIDTH 1280
# define PI 3.141592653589793//23846
# define tPI 6.28318530718
# define PII 1.57079632679
# define PIII 4.71238898038


// #include <time.h>
typedef struct s_ray
{
	double	rx;
	double	ry;
	double	xo;
	double	yo;
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

}		t_keyb;

typedef struct s_player
{
	t_keyb	keybind;
	double	xpos;
	double	ypos;
	double	xdelt;
	double	ydelt;
	double	angle;

}		t_player;

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

}		t_vars;

void	init_vars(t_vars *vars);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_window(t_vars *vars);
void	the_hooks(t_vars *vars);
int		handle_key_press(int keycode, t_vars *vars);
int		handle_key_release(int keycode, t_vars *vars);
int		every_frame(void *param);

void	draw_map(t_map map, t_vars *vars);
void	update_pos(t_player *player);
void	draw_rays(t_player player, t_map map, t_vars *vars);
int		draw_cube_player(t_player player, t_vars *vars);

//RAYCASTING
void	r_offset_calc(t_ray *ray, t_map map, t_player player);
int	r_hit_wall(t_ray ray, t_map map, t_vars *vars);

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	line_drawing(t_vars *vars, int x0, int y0, int x1, int y1);

#endif
