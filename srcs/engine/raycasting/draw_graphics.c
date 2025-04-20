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
		x_step = ((32.0 / l_height) + 0.01);
	if (l_height > (HEIGHT / 2))
		l_height = HEIGHT / 2;	
	int	image_size = vars->line_length * (HEIGHT / 2);
	bytes_per_pixel = vars->bits_per_pixel / 8;
	y = (HEIGHT / 3) - l_height / 2;
	// Get pointer to first pixel in the image buffer
	dst = vars->addr + (y * vars->line_length) + (r_nb * 10 *bytes_per_pixel);

	// CHANGE COLOR FROM TEXTURE
	i = 0;
	while (i < l_height) 
	{
		j = 0;
		xif = (int)(ray.rx / 4.0) % 32;
xif = (int)((ray.rx / 128.0) * 32) % 32;
		//x_step = ((32.0 / l_height) - 0.001);
		if (dst < vars->addr || dst + (10 * bytes_per_pixel) > vars->addr + image_size)
			break;
		while (j++ < 10)
		{
		t_color = *(unsigned int *)(vars->textures.t_addr + (ti * 32 * bytes_per_pixel) + ((int)xif * bytes_per_pixel));
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
	(void)ti;
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

