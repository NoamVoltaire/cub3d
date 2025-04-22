#include <cub.h>
#define TEX_SIZE 64

// static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray ray)
// {
// 	int		y, i, j;
// 	int		ti = 0;
// 	float	tif = 0.0;
// 	float	t_step = 32.0 / l_height;
// 	float	ty_off = 0;
// 	int		bytes_per_pixel = vars->bits_per_pixel / 8;
// 	char	*dst;
// 	char	*img_t_addr;

// 	if (l_height > HEIGHT / 2)
// 	{
// 		ty_off = (l_height - HEIGHT / 2) / 2.0;
// 		l_height = HEIGHT / 2;
// 	}
// 	tif = ty_off * t_step;
// 	ti = (int)tif;

// 	// Choose texture
// 	if (ray.hit_dir == 0 || ray.hit_dir == 1)
// 		img_t_addr = vars->textures.t_addr_no;
// 	else
// 		img_t_addr = vars->textures.t_addr_ea;

// 	y = (HEIGHT / 4) - (l_height / 2);
// 	dst = vars->addr + (y * vars->line_length) + (r_nb * 10 * bytes_per_pixel);

// 	for (i = 0; i < l_height; i++)
// 	{
// 		for (j = 0; j < 10; j++)
// 		{
// 			// Pixel offset across the 10px strip, centered around 0
// 			float px_shift = (float)j - 4.5f;
// 			// float offset = (px_shift / 10.0f) * TEX_SIZE * 0.5f;
// 			float offset = (px_shift / 10.0f) * TEX_SIZE * (256.0f / ray.hit_len);


// 			// Compute virtual sub-ray position in the tile
// 			float sample_x = ray.rx;
// 			float sample_y = ray.ry;

// 			if (ray.hit_dir == 0 || ray.hit_dir == 2) // horizontal wall
// 				sample_x += offset;
// 			else // vertical wall
// 				sample_y += offset;

// 			int tex_x;
// 			if (ray.hit_dir == 0 || ray.hit_dir == 2)
// 				tex_x = (int)fmod(sample_x, vars->map.tilesize) * TEX_SIZE / vars->map.tilesize;
// 			else
// 				tex_x = (int)fmod(sample_y, vars->map.tilesize) * TEX_SIZE / vars->map.tilesize;

// 			if (ray.hit_dir == 2 || ray.hit_dir == 3)
// 				tex_x = TEX_SIZE - tex_x - 1;

// 			unsigned int t_color = *(unsigned int *)(img_t_addr + (ti * TEX_SIZE + tex_x) * bytes_per_pixel);

// 			// Shading
// 			int r = (t_color >> 16) & 0xFF;
// 			int g = (t_color >> 8) & 0xFF;
// 			int b = t_color & 0xFF;
// 			if (ray.hit_dir == 1) { r /= 1.2; g /= 1.2; b /= 1.2; }
// 			if (ray.hit_dir == 2) { r >>= 1; g >>= 1; b >>= 1; }

// 			t_color = (r << 16) | (g << 8) | b;
// 			*(unsigned int *)dst = t_color;
// 			dst += bytes_per_pixel;
// 		}
// 		dst -= 10 * bytes_per_pixel;
// 		dst += vars->line_length;
// 		tif += t_step;
// 		ti = (int)tif;
// 	}
// }










// static void	ray_to_line(int r_nb, int l_height, t_vars *vars, t_ray ray)
// {
// 	int				y;
// 	int				i;
// 	int				j = 0;
// 	int				ti = 0;
// 	float				tif = 0.0;
// 	float				xif = 0.0;
// 	float				t_step;
// 	float				x_step;
// 	unsigned int			t_color;
// 	int				bytes_per_pixel;
// 	char			*dst;
// 	//int	row_sz = vars->line_length / 2;
// 	t_step = 32.0 / l_height;
// 	x_step = (((64.0)/ l_height) + 0.01 );
// 	// x_step = 0;
// 	float	ty_off = 0;
// 	if (l_height > (HEIGHT / 2))
// 	{
// 		ty_off = (l_height - (HEIGHT / 2)) / 2.0;
// 		l_height = HEIGHT / 2;
// 	}
// 	ti = ty_off * t_step;	// THIS IS THE THE STARTING Y TEXTURE VALUE, TY_OFF IS FOR WHEN WE'RE TOO CLOSE
// 	tif = ty_off * t_step;
// 	int	image_size = vars->line_length * (HEIGHT / 2);
// 	bytes_per_pixel = vars->bits_per_pixel / 8;
// 	y = (HEIGHT / 4) - l_height / 2;
// 	// Get pointer to first pixel in the image buffer
// 	dst = vars->addr + (y * vars->line_length) + (r_nb * 10 *bytes_per_pixel);

// 	// CHANGE COLOR FROM TEXTURE
// 	char *img_t_addr;
// 	if (ray.hit_dir == 0 || ray.hit_dir == 1)
// 		img_t_addr = vars->textures.t_addr_no;
// 	if (ray.hit_dir == 2 || ray.hit_dir == 3)
// 		img_t_addr = vars->textures.t_addr_ea;
// 	i = 0;

// 	float strip_center_offset = 5.0; // halfway of 10px
// float fov_correction = (strip_center_offset / ray.hit_len ) ; // tweak this scale if too strong

// float rx_offset = cos(ray.ra) * fov_correction;
// float ry_offset = sin(ray.ra) * fov_correction;

// float adjusted_rx = ray.rx + rx_offset;
// float adjusted_ry = ray.ry + ry_offset;


// 	while (i < l_height) 
// 	{

// // Flip if needed

// 		j = 0;
// 		if (ray.hit_dir == 0 || ray.hit_dir == 2)
// 		xif = fmod(adjusted_rx, vars->map.tilesize) * (32.0 / vars->map.tilesize);
// 		// xif = (int)(ray.rx / 2.0) % 32;
// 		else
// 		xif = fmod(adjusted_ry, vars->map.tilesize) * (32.0 / vars->map.tilesize);
// 		// xif = (int)(ray.ry / 2.0) % 32;
// 		int prev_xif = xif;
// 			xif = 0.5 * xif + 0.5 * prev_xif;
// 			if (ray.hit_dir == 2 || ray.hit_dir == 3)
// 				xif = TEX_SIZE - xif - 1;
		
// 	// printf("x_step = %f\n", x_step);
// 		// xif = (int)((ray.rx / 128.0) * 32) % 32;
// 		//x_step = ((32.0 / l_height) - 0.001);
// 		if (dst < vars->addr || dst + (10 * bytes_per_pixel) > vars->addr + image_size)
// 			break;
// 		while (j++ < 10)
// 		{
// 			t_color = *(unsigned int *)(img_t_addr + (ti * 32 * bytes_per_pixel) + ((int)xif * bytes_per_pixel));
// 			int	r = (t_color >> 16) & 0xFF;
// 			int	g = (t_color >> 8) & 0xFF;
// 			int	b = t_color & 0xFF;

// 		// Darken by 50% (adjust factor as needed)
// 			if (ray.hit_dir == 1)
// 			{
// 			r = r  / 1.2;
// 			g = g  / 1.2;
// 			b = b  / 1.2;
// 			}
// 			if (ray.hit_dir == 2)
// 			{
// 			r = r >> 1;
// 			g = g  >> 1;
// 			b = b  >> 1;
// 			}

// 	// Repack into t_color
// 			if (ray.hit_dir == 1 || ray.hit_dir == 2)
// 				t_color = (r << 16) | (g << 8) | b;
// 			*(unsigned int *) dst = t_color;
// 			dst += bytes_per_pixel;
// 			//xif += (ray.hit_len/1280) ;
// 			xif += x_step;
// 			//xif += (DR / 10.0);
// 		}
// 		dst -= (10 * bytes_per_pixel);
// 		//memcpy(dst, color_array, 10 * bytes_per_pixel); // Copy 8 pixels at once
// 		dst += vars->line_length; // Move to next row
// 		i++;
// 		tif += t_step;
// 		ti = (int)tif;
// 	}
// 	//(void)ti;
// }
















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
	t_step = (float)TEX_SIZE / l_height;
	x_step = (((float)(TEX_SIZE)/ l_height) + 0.01 );
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
			xif = fmod(ray.rx, vars->map.tilesize) * ((float)TEX_SIZE / vars->map.tilesize);
			// xif = (int)(ray.rx / 2.0) % 32;
		else
			xif = fmod(ray.ry, vars->map.tilesize) * ((float)TEX_SIZE / vars->map.tilesize);
			// xif = (int)(ray.ry / 2.0) % 32;
		// if (ray.hit_dir == 2)
		// 	xif = 31 - xif;
		// if (ray.hit_dir == 3)
		// 	xif = 31 - xif;
		if (ray.hit_dir == 2 || ray.hit_dir == 3)
			xif = TEX_SIZE - xif - 1;
	// printf("x_step = %f\n", x_step);
		// xif = (int)((ray.rx / 128.0) * 32) % 32;
		//x_step = ((32.0 / l_height) - 0.001);
		if (dst < vars->addr || dst + (10 * bytes_per_pixel) > vars->addr + image_size)
			break;
		while (j++ < 10)
		{
			t_color = *(unsigned int *)(img_t_addr + (ti * TEX_SIZE * bytes_per_pixel) + ((int)xif * bytes_per_pixel));
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
	// (void)x_step;
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

	line_height = (vars->map.tilesize * (HEIGHT  / 2)) / ray.hit_len;
	//printf("the value of lheight = %f\n", line_height);
	//printf("the value of ray.hitlen = %f\n", ray.hit_len);
	ray_to_line(ray_nb, (int)line_height, vars, ray);
}

