/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:55 by noam              #+#    #+#             */
/*   Updated: 2025/03/16 00:56:50 by noam             ###   ########.fr       */
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
# define HEIGHT 1080
# define WIDTH 1080
# define PI 3.14159265//358979323846

// #include <time.h>

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

void		init_vars(t_vars *vars);
void		init_map(t_map *map);
void		init_player(t_player *player);
void		init_window(t_vars *vars);
void		the_hooks(t_vars *vars);
int		handle_key_press(int keycode, t_vars *vars);
int		handle_key_release(int keycode, t_vars *vars);
int		every_frame(void *param);

void		draw_map(t_map map, t_vars *vars);
void		update_pos(t_player *player);
int		draw_cube_player(t_player player, t_vars *vars);
void		my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

#endif
