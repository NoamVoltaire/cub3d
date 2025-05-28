# include <cub.h>

static char	*get_texture_path(char *line, int j)
{
	int		len;
	int		i;
	char	*path;

	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	len = j;
	while (line[len] && (line[len] != ' ' && line[len] != '\t'))
		len++;
	path = malloc(sizeof(char) * (len - j + 1));
	if (!path)
		return (NULL);
	i = 0;
	while (line[j] && (line[j] != ' ' && line[j] != '\t' && line[j] != '\n'))
		path[i++] = line[j++];
	path[i] = '\0';
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	if (line[j] && line[j] != '\n')
	{
		free(path);
		path = NULL;
	}
	return (path);
}

int	line_into_texture_path(char *line, t_parse *parse, int j)
{
	if (!line[j + 2] && ft_isprint(line[j + 2]))
		return (1);
	if (line[j] == 'N' && line[j + 1] == 'O' && !(parse->t_paths[0]))
		parse->t_paths[0] = get_texture_path(line, j + 2);
	else if (line[j] == 'S' && line[j + 1] == 'O' && !(parse->t_paths[1]))
		parse->t_paths[1] = get_texture_path(line, j + 2);
	else if (line[j] == 'W' && line[j + 1] == 'E' && !(parse->t_paths[2]))
		parse->t_paths[2] = get_texture_path(line, j + 2);
	else if (line[j] == 'E' && line[j + 1] == 'A' && !(parse->t_paths[3]))
		parse->t_paths[3] = get_texture_path(line, j + 2);
	else
		return (1);
	return (0);
}
