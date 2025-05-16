/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:32 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/16 17:13:21 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	initialize_gnl_data(t_gnl *data, char *save, char **line, int fd)
{
	data->tmp_save = NULL;
	data->line = line;
	data->fd = fd;
	data->save = save;
	if (read(fd, 0, 0))
	{
		data->save[0] = '\0';
		perror("cub3D: read");
		return (-1);
	}
	return (0);
}

static void clean_data(t_gnl *data)
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

static int  get_save(t_gnl *data)
{
    size_t  i;

    i = 0;
    data->tmp_save = ft_strchr(*(data->line), '\n');
    if (data->tmp_save != NULL)
    {
        while (data->tmp_save[i + 1] != '\0')
        {
            data->save[i] = data->tmp_save[i + 1];
            data->tmp_save[i + 1] = '\0';
            i++;
        }
        data->tmp_save = NULL;
    }
    data->save[i] = '\0';
    return (0);
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

static int  get_line(t_gnl *data)
{
    int read_bytes;

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
            *(data->line) = ft_strjoin(data->tmp_save, data->save);
            free(data->tmp_save);
            data->tmp_save = NULL;
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
	t_gnl	data;
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
