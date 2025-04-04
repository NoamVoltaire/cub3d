#include <cub.h>

void	init_texture(t_vars *vars)
{
	t_texture	texture;
	void	*img;
	int bpp = 0, w = 0, h = 0;
	char	*t_addr;

	img = mlx_xpm_file_to_image(vars->mlx, "./ressources/h_stripe.xpm", &w, &h);
	if (img == NULL) {
	    printf("Failed to load image\n");
    return;  // Return early if image is not loaded
}
	t_addr = mlx_get_data_addr(img, &bpp, &w, &h);
printf("Width: %d, Height: %d, bpp: %d\n", w, h, bpp);
	texture.no_texture = img;
	texture.t_addr = t_addr;
	vars->textures = texture;

}
