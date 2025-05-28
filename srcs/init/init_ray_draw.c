/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:45:00 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:45:03 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_raydraw	init_ray_draw_data(int l_height, t_tex *tex)
{
	t_raydraw	d;
	float		ty_off;

	ty_off = 0;
	d.t_y_step = (float)tex->h / l_height;
	d.t_x_step = ((float)tex->w / l_height) + 0.01;
	if (l_height > HEIGHT)
	{
		ty_off = (l_height - HEIGHT) / 2.0;
		l_height = HEIGHT;
	}
	d.y_uv = ty_off * d.t_y_step;
	d.t_y = (int)(ty_off * d.t_y_step);
	d.l_height = l_height;
	d.y = (HEIGHT / 2) - l_height / 2;
	return (d);
}
