/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_display_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:52:37 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:52:40 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

t_tex	get_texture_addr(t_ray *ray, t_vars *vars)
{
	if (ray->hit_dir == 0)
		return (vars->textures.no);
	else if (ray->hit_dir == 1)
		return (vars->textures.ea);
	else if (ray->hit_dir == 2)
		return (vars->textures.so);
	else if (ray->hit_dir == 3)
		return (vars->textures.we);
	else
		return (vars->textures.no);
}

unsigned int	darken_color(unsigned int color, int dir)
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
