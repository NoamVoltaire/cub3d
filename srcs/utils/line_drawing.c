/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:32:42 by noam              #+#    #+#             */
/*   Updated: 2025/05/25 14:32:48 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	line_drawing(t_vars *vars, int x0, int y0, int x1, int y1) 
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	//(void)vars;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		//printf("x1 = %d\n y1 = %d\n", x1, y1);
		//printf("x0 = %d\n y0 = %d\n", x0, y0);
		my_mlx_pixel_put(vars, x0, y0,03770000);

		if ((x0 == x1 && y0 == y1) || x0 == 1 || y0 == 1 || x0 > WIDTH || y0 > HEIGHT)
			break;
		if (err * 2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (err * 2 < dx)
		{
			err += dx;
			y0 += sy;
		}

	}
	//printf("line drawn\n\n");

}

