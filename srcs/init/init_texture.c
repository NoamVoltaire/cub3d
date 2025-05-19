#include <cub.h>

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

void	init_textures(t_vars *vars)
{
	t_texture	texture;

	texture.t_addr_no = get_textures_adrr(vars, &texture.no_texture, "./ressources/d_64.xpm");
	texture.t_addr_ea = get_textures_adrr(vars, &texture.ea_texture, "./ressources/d_64.xpm");
	//need the other adresses of course
	//also needs a function to free those images
	//thinking of adding height and width in t_texture
	vars->textures = texture;
	//mlx_image

}
