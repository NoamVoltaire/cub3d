#include <cub.h>



static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray ray)
{
	int				y;
	int				i;
	int				j = 0;
	int				ti = 0;
	float				tif = 0.0;
	float				xif = 0.0;
	float				t_step;
	float				x_step;
	unsigned int			t_color;
	int				bytes_per_pixel;
	char			*dst;
	//int	row_sz = vars->line_length / 2;
	t_step = 32.0 / l_height;
	x_step = (((32.0)/ l_height) + 0.01 );
	// x_step = 0;
	float	ty_off = 0;
	if (l_height > (HEIGHT / 2))
	{
		ty_off = (l_height - (HEIGHT / 2)) / 2.0;
		l_height = HEIGHT / 2;
	}
	ti = ty_off * t_step;	// THIS IS THE THE STARTING Y TEXTURE VALUE, TY_OFF IS FOR WHEN WE'RE TOO CLOSE
	tif = ty_off * t_step;
	int	image_size = vars->line_length * (HEIGHT / 2);
	bytes_per_pixel = vars->bits_per_pixel / 8;
	y = (HEIGHT / 4) - l_height / 2;
	// Get pointer to first pixel in the image buffer
	dst = vars->addr + (y * vars->line_length) + (r_nb * 10 *bytes_per_pixel);

	// CHANGE COLOR FROM TEXTURE
	char *img_t_addr;
	if (ray.hit_dir == 0 || ray.hit_dir == 1)
		img_t_addr = vars->textures.t_addr_no;
	if (ray.hit_dir == 2 || ray.hit_dir == 3)
		img_t_addr = vars->textures.t_addr_ea;
	i = 0;

	while (i < l_height) 
	{
		j = 0;
		if (ray.hit_dir == 0 || ray.hit_dir == 2)
			xif = (int)(ray.rx / 4.0) % 32;
		else
			xif = (int)(ray.ry / 4.0) % 32;
		if (ray.hit_dir == 2)
			xif = 31 - xif;
		if (ray.hit_dir == 3)
			xif = 31 - xif;
	// printf("x_step = %f\n", x_step);
		// xif = (int)((ray.rx / 128.0) * 32) % 32;
		//x_step = ((32.0 / l_height) - 0.001);
		if (dst < vars->addr || dst + (10 * bytes_per_pixel) > vars->addr + image_size)
			break;
		while (j++ < 10)
		{
			t_color = *(unsigned int *)(img_t_addr + (ti * 32 * bytes_per_pixel) + ((int)xif * bytes_per_pixel));
			int	r = (t_color >> 16) & 0xFF;
			int	g = (t_color >> 8) & 0xFF;
			int	b = t_color & 0xFF;

		// Darken by 50% (adjust factor as needed)
			if (ray.hit_dir == 1)
			{
			r = r  / 1.2;
			g = g  / 1.2;
			b = b  / 1.2;
			}
			if (ray.hit_dir == 2)
			{
			r = r >> 1;
			g = g  >> 1;
			b = b  >> 1;
			}

	// Repack into t_color
			if (ray.hit_dir == 1 || ray.hit_dir == 2)
				t_color = (r << 16) | (g << 8) | b;
			*(unsigned int *) dst = t_color;
			dst += bytes_per_pixel;
			//xif += (ray.hit_len/1280) ;
			xif += x_step;
			//xif += (DR / 10.0);
		}
		dst -= (10 * bytes_per_pixel);
		//memcpy(dst, color_array, 10 * bytes_per_pixel); // Copy 8 pixels at once
		dst += vars->line_length; // Move to next row
		i++;
		tif += t_step;
		ti = (int)tif;
	}
	//(void)ti;
}

//static	void	ray_to_line(int r_nb, int l_height, t_vars *vars)
//{
//	int	i;
//	int	j;
//	int	x;
//	int	y;
//
//	i = 0;
//	y = (HEIGHT /3) - l_height / 2;
//	x = r_nb * 4;
//		//printf("heyyyyyyyy\n");
//		//printf("the value of lheight = %d\n", l_height);
//	while (i < l_height)
//	{
//	//	printf("helloooooooooo\n");
//		j = x;
//	printf("j = %d\n y = %d\n", j, y);
//		while (j < x + 4)
//		{
//			my_mlx_pixel_put(vars, j, y, 0x000000FF);
//			j++;
//		}
//		y++;
//		i++;
//	}
//}

		
		

void	draw_graphics(t_ray ray, int ray_nb, t_vars *vars)
{
	float	line_height;

	line_height = (64 * HEIGHT  / 2) / ray.hit_len;
	//printf("the value of lheight = %f\n", line_height);
	//printf("the value of ray.hitlen = %f\n", ray.hit_len);
	ray_to_line(ray_nb, (int)line_height, vars, ray);
}

