/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_gnl_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrellie <lgrellie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:29:32 by lgrellie          #+#    #+#             */
/*   Updated: 2025/05/28 10:04:15 by lgrellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	initialize_gnl_data(t_gnl *data, char *save, char **line, int fd)
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

int	get_save(t_gnl *data)
{
	size_t	i;

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
