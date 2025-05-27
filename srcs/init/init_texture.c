/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:31:56 by noam              #+#    #+#             */
/*   Updated: 2025/05/25 14:36:41 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

char	*fill_floor_ceiling_array(t_vars *vars, int color)
{
	char	*row;
	int		bytes;
	int		i;

	i = 0;
	bytes = vars->bits_per_pixel / 8;
	row = malloc(sizeof(char) * WIDTH * (vars->bits_per_pixel / 8));
	while (i++ < WIDTH - 1)
		memcpy(row + i * bytes, &color, bytes);
	return (row);
}

t_tex	get_tex(t_vars *vars, char *path)
{
	t_tex	tex;
	int		bpp;
	int		w;
	int		h;

	bpp = 0;
	w = 0;
	h = 0;
	tex.img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	tex.w = w;
	tex.h = h;

	//printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
	if (tex.img == NULL)
	{
		printf("Failed to load image\n");
		exit(1);										//TODO
		//return (NULL);
	}
	tex.addr = mlx_get_data_addr(tex.img, &bpp, &w, &h);
	return (tex);
}

void	init_textures(t_vars *vars, int floor_col, int ceiling_col)
{
	t_texture	texture;
	char		*floor_;
	char		*ceiling_;

	texture.no = get_tex(vars, vars->parse.t_paths[0]);
	texture.so = get_tex(vars, vars->parse.t_paths[1]);
	texture.we = get_tex(vars, vars->parse.t_paths[2]);
	texture.ea = get_tex(vars, vars->parse.t_paths[3]);
	//also needs a function to free those images
	floor_ = fill_floor_ceiling_array(vars, floor_col);
	ceiling_ = fill_floor_ceiling_array(vars, ceiling_col);


	vars->textures = texture;
	vars->textures.floor = floor_;
	vars->textures.ceiling = ceiling_;
}
