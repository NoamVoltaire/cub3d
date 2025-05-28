/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:32 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/28 10:43:27 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	clean_data(t_gnl *data)
{
	data->save[0] = '\0';
	if (data->tmp_save != NULL)
	{
		free(data->tmp_save);
		data->tmp_save = NULL;
	}
	if (*(data->line) != NULL)
	{
		free(*(data->line));
		*(data->line) = NULL;
	}
}

static char	*custom_strjoin(char **temp, char *save)
{
	char	*joined;

	joined = ft_strjoin(*temp, save);
	free(*temp);
	*temp = NULL;
	return (joined);
}

static int	safe_read(t_gnl *data, int *read_bytes)
{
	*read_bytes = read(data->fd, data->save, BUFFER_SIZE);
	if (*read_bytes == -1)
	{
		perror("cub3D: read");
		return (-1);
	}
	data->save[*read_bytes] = '\0';
	return (0);
}

int	get_line(t_gnl *data)
{
	int	read_bytes;

	read_bytes = 1;
	*(data->line) = ft_strdup(data->save);
	if (*(data->line) == NULL)
	{
		perror("cub3D: malloc");
		return (-1);
	}
	while (read_bytes > 0 && ft_strchr(*(data->line), '\n') == NULL)
	{
		if (safe_read(data, &read_bytes) == -1)
			return (-1);
		if (read_bytes != 0)
		{
			data->tmp_save = *(data->line);
			*(data->line) = custom_strjoin(&data->tmp_save, data->save);
			if (*(data->line) == NULL)
			{
				perror("cub3D: malloc");
				return (-1);
			}
		}
	}
	return (0);
}

int	next_gnl(char **line, int fd)
{
	t_gnl		data;
	static char	save[BUFFER_SIZE + 1];

	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (GNL_ERANGE);
	if (initialize_gnl_data(&data, save, line, fd) == -1)
		return (GNL_ESYS);
	if (get_line(&data) == -1)
	{
		clean_data(&data);
		return (GNL_ESYS);
	}
	if (*(data.line)[0] == '\0')
	{
		clean_data(&data);
		return (GNL_EOF);
	}
	if (get_save(&data) == -1)
	{
		clean_data(&data);
		return (GNL_ESYS);
	}
	return (GNL_SUCCESS);
}
