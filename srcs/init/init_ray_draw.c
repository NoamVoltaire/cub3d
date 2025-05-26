
#include <cub.h>

t_raydraw	init_ray_draw_data(int l_height, t_tex *tex)
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
