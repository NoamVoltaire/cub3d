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
//#include <stdlib.h>

char	*fill_floor_ceiling_array(t_vars *vars, int color)
{
	char	*row;
	int		bytes;
	int		i;
	//char	row[WIDTH * (vars->bits_per_pixel / 8)];

	//row = NULL;
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
	//char	*addr;
	int		bpp;
	int		w;
	int		h;

	bpp = 0;
	w = 0;
	h = 0;
	tex.img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	tex.w = w;
	tex.h = h;

	printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
	if (tex.img == NULL)
	{
		printf("Failed to load image\n");
		exit(1);										//TODO
		//return (NULL);
	}
	tex.addr = mlx_get_data_addr(tex.img, &bpp, &w, &h);
	//addr = mlx_get_data_addr(img, &bpp, &w, &h);
	return (tex);
}

//char	*get_textures_adrr(t_vars *vars, void **img, char *path)
//{
//	char	*addr;
//	int		bpp;
//	int		w;
//	int		h;
//
//	bpp = 0;
//	w = 0;
//	h = 0;
//	img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
//
//	printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
//	if (img == NULL)
//	{
//		printf("Failed to load image\n");
//		return (NULL);
//	}
//	addr = mlx_get_data_addr(img, &bpp, &w, &h);
//	return (addr);
//}

//t_tex	get_tex(t_vars *vars, char *path)
//{
//	t_tex	tex;
//
//	tex.t_addr_no = get_textures_adrr(vars, &tex.no_texture, path);
//}

void	init_textures(t_vars *vars, int floor_col, int ceiling_col)
{
	t_texture	texture;
	char		*floor_;
	char		*ceiling_;

	//texture.t_addr_no = get_textures_adrr(vars, &texture.no_texture, "./ressources/d_64.xpm");
	//texture.no = get_tex(vars, "./ressources/d_126.xpm");
	texture.no = get_tex(vars, vars->parse.t_paths[0]);
	texture.so = get_tex(vars, vars->parse.t_paths[1]);
	texture.we = get_tex(vars, vars->parse.t_paths[2]);
	texture.ea = get_tex(vars, vars->parse.t_paths[3]);
	//texture.so = get_tex(vars, "./ressources/d_126.xpm");
	//texture.we = get_tex(vars, "./ressources/d_64.xpm");
	//texture.ea = get_tex(vars, "./ressources/d_64.xpm");
	//texture.t_addr_ea = get_textures_adrr(vars, &texture.ea_texture, "./ressources/d_64.xpm");
	//need the other adresses of course
	//also needs a function to free those images
	//thinking of adding height and width in t_texture
	floor_ = fill_floor_ceiling_array(vars, floor_col);
	ceiling_ = fill_floor_ceiling_array(vars, ceiling_col);


	vars->textures = texture;
	vars->textures.floor = floor_;
	vars->textures.ceiling = ceiling_;
	//mlx_image

}
