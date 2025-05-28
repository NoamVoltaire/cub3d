/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_graphics.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:33:25 by noam              #+#    #+#             */
/*   Updated: 2025/05/25 14:33:28 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

static float	calculate_x_uv(t_ray *ray, t_vars *vars, t_tex *tex)
{
	float	x_uv;

	if (ray->hit_dir == 0 || ray->hit_dir == 2)
		x_uv = fmod(ray->rx, vars->map.tilesize)
			* ((float)tex->w / vars->map.tilesize);
	else
		x_uv = fmod(ray->ry, vars->map.tilesize)
			* ((float)tex->w / vars->map.tilesize);
	if (ray->hit_dir == 2 || ray->hit_dir == 3)
		x_uv = tex->w - x_uv - 1;
	return (x_uv);
}

static void	draw_strips(t_vars *vars, t_ray *ray, t_tex *tex, char *dst)
{
	unsigned int	color;
	int				j;
	int				bytes;
	int				y;

	j = 0;
	bytes = vars->bits_per_pixel / 8;
	y = (ray->render.t_y * tex->w * bytes);
	while (j++ < 10)
	{
		color = *(unsigned int *)(tex->addr + y
				+ ((int)ray->render.x_uv * bytes));
		if (ray->hit_dir == 1 || ray->hit_dir == 2)
			color = darken_color(color, ray->hit_dir);
		*(unsigned int *)dst = color;
		dst += bytes;
		ray->render.x_uv += ray->render.t_x_step;
	}
}

static void	draw_column_pixels(t_vars *vars, t_ray *ray, t_tex *tex, int ray_nb)
{
	char	*dst;
	int		i;
	int		bytes;
	int		x_u;

	i = 0;
	bytes = vars->bits_per_pixel / 8;
	dst = vars->addr + (ray->render.y * vars->line_length)
		+ (ray_nb * 10 * bytes);
	x_u = calculate_x_uv(ray, vars, tex);
	while (i < ray->render.l_height)
	{
		ray->render.x_uv = x_u; 
		draw_strips(vars, ray, tex, dst);
		dst += vars->line_length;
		i++;
		ray->render.y_uv += ray->render.t_y_step;
		ray->render.t_y = (int)ray->render.y_uv;
	}
}

static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray *ray)
{
	t_tex		tex;

	tex = get_texture_addr(ray, vars);
	ray->render = init_ray_draw_data(l_height, &tex);
	draw_column_pixels(vars, ray, &tex, r_nb);
}

void	draw_graphics(t_ray *ray, int ray_nb, t_vars *vars)
{
	float	line_height;

	line_height = (vars->map.tilesize * HEIGHT / ray->hit_len);
	ray_to_line(ray_nb, (int)line_height, vars, ray);
}
