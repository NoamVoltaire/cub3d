#include <cub.h>
#include <stdlib.h>

char	*fill_floor_ceiling_array(t_vars *vars, int color)
{
	//char	row[WIDTH * (vars->bits_per_pixel / 8)];
	char	*row;
	int		bytes;
	int		i;

	i = 0;
	bytes = vars->bits_per_pixel / 8;
	row = malloc(sizeof(char) * WIDTH * (vars->bits_per_pixel / 8));
	while (i++ < WIDTH)
		memcpy(row + i * bytes, &color, bytes);
	return (row);
}

char	*get_textures_adrr(t_vars *vars, void **img, char *path)
{
	char	*addr;
	int		bpp;
	int		w;
	int		h;

	bpp = 0;
	w = 0;
	h = 0;
	img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	if (img == NULL)
	{
		printf("Failed to load image\n");
		return (NULL);
	}
	addr = mlx_get_data_addr(img, &bpp, &w, &h);
	return (addr);
	printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
}

void	init_textures(t_vars *vars, int floor_col, int ceiling_col)
{
	t_texture	texture;
	char	*floor_;
	char	*ceiling_;

	texture.t_addr_no = get_textures_adrr(vars, &texture.no_texture, "./ressources/d_64.xpm");
	texture.t_addr_ea = get_textures_adrr(vars, &texture.ea_texture, "./ressources/d_64.xpm");
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
