#include <cub.h>

//typedef struct {
//	int **data;
//	int width;
//	int height;
//} t_map;

int	is_edge(int x, int y, t_parse *parse)
{
	return (x == 0 || y == 0 || x == parse->m_w - 1 || y == parse->m_h - 1 || parse->tab[x][y] == '1');
}

int	is_valid(t_parse *parse, int x, int y, int target)
{
	if (x < 0 || y < 0 || x >= parse->m_w || y >= parse->m_h)
		return (0);
	if (parse->tab[y][x] == -1)
		return (0);
	return (parse->tab[y][x] == target);
}

int	flood_cell(t_parse *parse, int x, int y, int target)
{
	int	a;
	int	b;
	int	c;
	int	d;

	if (!is_valid(parse, x, y, target))
		return (1);
	if (is_edge(x, y, parse))
		return (0);
	parse->tab[y][x] = -1;
	a = flood_cell(parse, x + 1, y, target);
	b = flood_cell(parse, x - 1, y, target);
	c = flood_cell(parse, x, y + 1, target);
	d = flood_cell(parse, x, y - 1, target);
	return (a && b && c && d);
}

int	flood_fill_map(t_parse *parse, int x, int y)
{
	int	target;

	target = parse->tab[y][x];
	if (target == -1)
		return (0);
	return (flood_cell(parse, x, y, target));
}

