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
#define TEX_SIZE 64

#include <time.h>



//typedef struct s_raydraw {
//	float	t_y_step;
//	float	t_x_step;
//	float	y_uv;
//	int		t_y;
//	int		l_height;
//	int		y;
//}	t_raydraw;

static t_raydraw	init_ray_draw_data(int l_height, t_tex *tex)
{
	t_raydraw	d;
	float		ty_off;

	ty_off = 0;
	d.t_y_step = (float)tex->h / l_height;
	d.t_x_step = ((float)tex->w / l_height) + 0.01;
	//here we calculate the step distance to walk the texture, using l_height
	if (l_height > HEIGHT)
	{
		ty_off = (l_height - HEIGHT) / 2.0;
		l_height = HEIGHT;
	}
	d.y_uv = ty_off * d.t_y_step;
	//this whole ty_off thing is if column larger than HEIGHT , then
	//truncate and apply y offest on texture
	d.t_y = (int)(ty_off * d.t_y_step);
	d.l_height = l_height;
	d.y = (HEIGHT / 2) - l_height / 2;
	// Get pointer to first pixel in of the column in the image buffer
	return (d);
}

static inline t_tex	get_texture_addr(t_ray *ray, t_vars *vars)
{
	if (ray->hit_dir == 0)
		return (vars->textures.no);
	else if (ray->hit_dir == 1)
		return (vars->textures.ea);
	else if (ray->hit_dir == 2)
		return (vars->textures.so);
	else if  (ray->hit_dir == 3)
		return (vars->textures.we);
	else
		return (vars->textures.no);
}

//static inline char	*get_texture_addr(t_ray *ray, t_vars *vars)
//{
//	if (ray->hit_dir == 0 || ray->hit_dir == 1)
//		return (vars->textures.no.addr);
//	if (ray->hit_dir == 2 || ray->hit_dir == 3)
//		return (vars->textures.ea.addr);
//	return (NULL);
//}

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

static inline unsigned int	darken_color(unsigned int color, int dir)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	if (dir == 1)
	{
		r = r / 1.2;
		g = g / 1.2;
		b = b / 1.2;
	}
	else if (dir == 2)
	{
		r >>= 1;
		g >>= 1;
		b >>= 1;
	}
	return ((r << 16) | (g << 8) | b);
}

static void	draw_strips(t_vars *vars, t_ray *ray, t_tex *tex, char *dst)
{
	unsigned int	color;
	int				j;
	int				bytes;
	int				y;

	j = 0;
	bytes = vars->bits_per_pixel / 8;
	y = (ray->render.t_y * tex->h * bytes);
	//int	image_size = vars->line_length * HEIGHT;
	while (j++ < 10)
	{
		color = *(unsigned int *)(tex->addr + y + ((int)ray->render.x_uv * bytes));
		if (ray->hit_dir == 1 || ray->hit_dir == 2)
			color = darken_color(color, ray->hit_dir);
		*(unsigned int *)dst = color;
		dst += bytes;
		ray->render.x_uv += ray->render.t_x_step;
	}
}
static void	draw_column_pixels(t_vars *vars, t_ray *ray, t_tex *tex, int ray_nb)
{
	int	i;
	int	bytes;
	char	*dst;
	int	x_u;
	//int	image_size;

	i = 0;
	bytes = vars->bits_per_pixel / 8;
	//image_size = vars->line_length * HEIGHT;
	dst = vars->addr + (ray->render.y * vars->line_length) + (ray_nb * 10 * bytes);

	x_u = calculate_x_uv(ray, vars, tex);
	while (i < ray->render.l_height)
	{

		ray->render.x_uv = x_u; 
		//if (dst < vars->addr || dst + (10 * bytes) > vars->addr + image_size)
			//break;
		draw_strips(vars, ray, tex, dst);
		//dst -= 10 * bytes;
		dst += vars->line_length;
		i++;
		ray->render.y_uv += ray->render.t_y_step;
		ray->render.t_y = (int)ray->render.y_uv;
	}
}

static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray *ray)
{
	//char		*texture;
	t_tex		tex;

	//texture = get_texture_addr(ray, vars);
	tex = get_texture_addr(ray, vars);
	ray->render = init_ray_draw_data(l_height, &tex);
//clock_t start = clock();
// run your function
	draw_column_pixels(vars, ray, &tex, r_nb);
//clock_t end = clock();
//printf("Elapsed: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
}

void	draw_graphics(t_ray *ray, int ray_nb, t_vars *vars)
{
	float	line_height;

	line_height = (vars->map.tilesize * HEIGHT / ray->hit_len);
	ray_to_line(ray_nb, (int)line_height, vars, ray);
}




//static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray ray)
//{
//	int				y;
//	int				i;
//	int				j = 0;
//	int				t_y = 0;
//	float				y_uv = 0.0;
//	float				x_uv = 0.0;
//	float				t_y_step;
//	float				t_x_step;
//	unsigned int			t_color;
//	int				bytes_per_pixel;
//	char			*dst;
//
//	t_y_step = (float)TEX_SIZE / l_height;
//	t_x_step = (((float)(TEX_SIZE)/ l_height) + 0.01 );
//	//here we calculate the step distance to walk the texture, using l_height
//
//	float	ty_off = 0;
//	if (l_height > HEIGHT)
//	{
//		ty_off = (l_height - HEIGHT) / 2.0;
//		l_height = HEIGHT;
//	}
//	t_y = ty_off * t_y_step;	// THIS IS THE THE STARt_yNG Y TEXTURE VALUE, TY_OFF IS FOR WHEN WE'RE TOO CLOSE
//	y_uv = ty_off * t_y_step;
//
//	int	image_size = vars->line_length * HEIGHT;
//	bytes_per_pixel = vars->bits_per_pixel / 8;
//	y = (HEIGHT / 4) - l_height / 2;
//	// Get pointer to first pixel in the image buffer
//	dst = vars->addr + (y * vars->line_length) + (r_nb * 10 *bytes_per_pixel);
//
//	// CHANGE COLOR FROM TEXTURE
//	char *img_t_addr;
//	if (ray.hit_dir == 0 || ray.hit_dir == 1)
//		img_t_addr = vars->textures.t_addr_no;
//	if (ray.hit_dir == 2 || ray.hit_dir == 3)
//		img_t_addr = vars->textures.t_addr_ea;
//	//here is where we assign img_texture adress to the correct one
//	i = 0;
//
//	while (i < l_height) 
//	{
//		j = 0;
//		//here we're gonna see what ray.rx means in : a map.tilesize
//		//we then convert that to TEX_SIZE scale
//		if (ray.hit_dir == 0 || ray.hit_dir == 2)
//			x_uv = fmod(ray.rx, vars->map.tilesize) * ((float)TEX_SIZE / vars->map.tilesize);
//		else
//			x_uv = fmod(ray.ry, vars->map.tilesize) * ((float)TEX_SIZE / vars->map.tilesize);
//		if (ray.hit_dir == 2 || ray.hit_dir == 3)
//			x_uv = TEX_SIZE - x_uv - 1;
//		//here if wall are north or south , we invert x_uv 
//		if (dst < vars->addr || dst + (10 * bytes_per_pixel) > vars->addr + image_size)
//			break;
//		while (j++ < 10)
//		{
//			t_color = *(unsigned int *)(img_t_addr + (t_y * TEX_SIZE * bytes_per_pixel) + ((int)x_uv * bytes_per_pixel));
//			int	r = (t_color >> 16) & 0xFF;
//			int	g = (t_color >> 8) & 0xFF;
//			int	b = t_color & 0xFF;
//
//		// Darken by 50% (adjust factor as needed)
//			if (ray.hit_dir == 1)
//			{
//			r = r  / 1.2;
//			g = g  / 1.2;
//			b = b  / 1.2;
//			}
//			if (ray.hit_dir == 2)
//			{
//			r = r >> 1;
//			g = g  >> 1;
//			b = b  >> 1;
//			}
//
//	// Repack into t_color
//			if (ray.hit_dir == 1 || ray.hit_dir == 2)
//				t_color = (r << 16) | (g << 8) | b;
//			*(unsigned int *) dst = t_color;
//			dst += bytes_per_pixel;
//			//x_uv += (ray.hit_len/1280) ;
//			x_uv += t_x_step;
//			//x_uv += (DR / 10.0);
//		}
//		dst -= (10 * bytes_per_pixel);
//		//memcpy(dst, color_array, 10 * bytes_per_pixel); // Copy 8 pixels at once
//		dst += vars->line_length; // Move to next row
//		i++;
//		y_uv += t_y_step;
//		t_y = (int)y_uv;
//	}
//	//(void)t_y;
//	// (void)t_x_step;
//}
//
//		
//		
//
//void	draw_graphics(t_ray ray, int ray_nb, t_vars *vars)
//{
//	float	line_height;
//
//	line_height = (vars->map.tilesize * (HEIGHT  / 2)) / ray.hit_len;
//	//printf("the value of lheight = %f\n", line_height);
//	//printf("the value of ray.hitlen = %f\n", ray.hit_len);
//	ray_to_line(ray_nb, (int)line_height, vars, ray);
//}
//
