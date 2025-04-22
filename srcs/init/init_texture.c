#include <cub.h>

char	*get_textures_adrr(t_vars *vars, void *img, char *path)
{
	char	*addr;
	int		bpp;
	int		w;
	int		h;

	bpp = 0;
	w = 0;
	h = 0;
	img = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
	if (img == NULL) {
	    printf("Failed to load image\n");
    return (NULL);  // Return early if image is not loaded
	}
	addr = mlx_get_data_addr(img, &bpp, &w, &h);
	return (addr);
	printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);

	// texture->no_texture = img;
	// texture->t_addr_no = t_addr;
}

void	init_textures(t_vars *vars)
{
	t_texture	texture;

	texture.t_addr_no = get_textures_adrr(vars, texture.no_texture, "./ressources/d_64.xpm");
	texture.t_addr_ea = get_textures_adrr(vars, texture.ea_texture, "./ressources/d_64.xpm");
// 	void	*img;
// 	int bpp = 0, w = 0, h = 0;u
// 	char	*t_addr;

// 	img = mlx_xpm_file_to_image(vars->mlx, "./ressources/h_stripe.xpm", &w, &h);
// 	if (img == NULL) {
// 	    printf("Failed to load image\n");
//     return;  // Return early if image is not loaded
// }
// 	t_addr = mlx_get_data_addr(img, &bpp, &w, &h);
// printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
// 	texture.no_texture = img;
// 	texture.t_addr = t_addr;
	vars->textures = texture;

}
