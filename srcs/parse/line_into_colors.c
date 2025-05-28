#include <cub.h>

static int	validate_rgb(char **rgb)
{
	int	count;
	int	val;

	count = 0;
	while (rgb[count])
	{
		val = ft_atoi(rgb[count]);
		if (count >= 3 || val < 0 || val > 255)
			return (0);
		count++;
	}
	return (count == 3);
}

static void	set_rgb_colors(char *line, int color_arr[4], t_parse *parse)
{
	char	**rgb;
	int		j;

	rgb = ft_split(line, ',');
	if (!validate_rgb(rgb))
	{
		free_tab(rgb);
		handle_parse_error(parse, ERR_COLOR_RANGE);
	}
	j = 0;
	while (j < 3)
	{
		color_arr[j] = ft_atoi(rgb[j]);
		j++;
	}
	color_arr[3] = 1;
	free_tab(rgb);
}

int	line_into_color_textures(t_parse *parse, char *line, int j)
{
	if (line[j + 1] && ft_isprint(line[j + 1]))
	{
		if (parse->c_color_input[3] == 0 && line[j] == 'C')
		{
			set_rgb_colors(line + j + 1, parse->c_color_input, parse);
			if (parse->c_color_input[3] == 0)
				handle_parse_error(parse, ERR_COLOR_FORMAT);
		}
		else if (parse->f_color_input[3] == 0 && line[j] == 'F')
		{
			set_rgb_colors(line + j + 1, parse->f_color_input, parse);
			if (parse->f_color_input[3] == 0)
				handle_parse_error(parse, ERR_COLOR_FORMAT);
		}
	}
	else
		handle_parse_error(parse, ERR_COLOR_FORMAT);
	return (0);
}
