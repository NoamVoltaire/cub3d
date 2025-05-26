/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:48:55 by noam              #+#    #+#             */
/*   Updated: 2025/05/26 08:17:23 by lgrellie         ###   ########.fr       */
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
# include "libft.h"
# define HEIGHT 1880
# define WIDTH 2540
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

typedef	struct s_textures
{
	void	*no_texture;
	void	*so_texture;
	void	*we_texture;
	void	*ea_texture;
	char	*t_addr_no;
	char	*t_addr_ea;
}	t_textures;
// #include <time.h>
typedef struct s_ray
{
	double	ra;
	double	rx;
	double	ry;
	double	xo;
	double	yo;
	int	hit_data;
	int	hit_dir;
	float	hit_len;
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
	t_texture	textures;

}		t_vars;

int		main_loop(t_vars vars);

//PARSING
int		print_error_msg(char *msg);
int		parse_into_vars(int fd, t_vars *vars);
int		next_gnl(char **line, int fd);

void	init_vars(t_vars *vars);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_window(t_vars *vars);
void	init_textures(t_vars *vars);
void	the_hooks(t_vars *vars);
int close_window(t_vars *vars);
int		handle_key_press(int keycode, t_vars *vars);
int		handle_key_release(int keycode, t_vars *vars);
int	escape(int keycode,t_vars *vars);
int		every_frame(void *param);

void	draw_map(t_map map, t_vars *vars);
void	update_pos(t_player *player, t_map map);
void	draw_rays(t_player player, t_map map, t_vars *vars);
int		draw_cube_player(t_player player, t_vars *vars);

//RAYCASTING
t_ray	casting(t_player player, t_map map, t_vars *vars, double ra);
void	r_offset_calc_x(t_ray *ray, t_map map, t_player player, double ra);
void	r_offset_calc_y(t_ray *ray, t_map map, t_player player, double ra);
float	r_hit_wall(t_ray *ray, t_map map, t_vars *vars);

void	draw_graphics(t_ray ray, int ray_nb, t_vars *vars);

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	line_drawing(t_vars *vars, int x0, int y0, int x1, int y1);

#endif
