#include <cub.h>

int	flood_cell(t_parse *parse, int x, int y)
{
	int	a;
	int	b;
	int	c;
	int	d;

	if (x < 0 || y < 0 || x >= parse->m_w || y >= parse->m_h)
		return (0);
	if (parse->tab[y][x] != 0)
		return (1);
	parse->tab[y][x] = -1;
	a = flood_cell(parse, x + 1, y);
	b = flood_cell(parse, x - 1, y);
	c = flood_cell(parse, x, y + 1);
	d = flood_cell(parse, x, y - 1);
	return (a && b && c && d);
}

int	flood_fill_map(t_parse *parse, int x, int y)
{
	return (flood_cell(parse, x, y));
}
