/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:40:41 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/28 10:40:47 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	check_args_before_map(t_parse *parse)
{
	int	fd;
	int	i;

	i = 0;
	fd = 0;
	while (i < 4)
	{
		if (!parse->t_paths[i])
			handle_parse_error(parse, ERR_MISSING_TEXTURE);
		fd = open(parse->t_paths[i], O_RDONLY);
		if (fd < 0)
			handle_parse_error(parse, ERR_FILE_OPEN);
		close(fd);
		i++;
	}
}

int	ignore_space_get_info(char *line, t_parse *parse)
{
	int	j;

	j = 0;
	while (line[j] == ' ' || line[j] == '\t' || line[j] == '\n')
		j++;
	if (ft_isprint(line[j]) && !ft_isdigit(line[j]))
	{
		if (line[j + 1] && (line[j] == 'C' || line[j] == 'F' ))
		{
			if (line_into_color_textures(parse, line, j))
				handle_parse_error(parse, ERR_COLOR_FORMAT);
		}
		else if (line[j + 1] && ft_isprint(line[j + 1])
			&& !ft_isdigit(line[j + 1]))
		{
			if (line_into_texture_path(line, parse, j))
				handle_parse_error(parse, ERR_COLOR_FORMAT);
		}
	}
	return (0);
}

void	initialize_vars(t_list *lst, t_parse *parse)
{
	parse->t_paths[0] = NULL;
	parse->t_paths[1] = NULL;
	parse->t_paths[2] = NULL;
	parse->t_paths[3] = NULL;
	ft_memset(parse->c_color_input, 0, sizeof(parse->c_color_input));
	ft_memset(parse->f_color_input, 0, sizeof(parse->f_color_input));
	parse->c_color_input[3] = 0;
	parse->f_color_input[3] = 0;
	parse->m_has_player = 0;
	while (lst && lst->content)
	{
		if (lst->content && !is_map_line(lst->content))
		{
			if (ignore_space_get_info(lst->content, parse))
				handle_parse_error(parse, ERR_MAP_FORMAT);
		}
		lst = lst->next;
	}
	check_args_before_map(parse);
}
