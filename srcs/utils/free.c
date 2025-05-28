/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:53:20 by nvoltair          #+#    #+#             */
/*   Updated: 2025/05/28 10:57:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	free_parse(t_parse *parse)
{
	int	i;

	i = 0;
	if (!parse)
		return ;
	while (i < 4)
	{
		if (parse->t_paths[i])
			free(parse->t_paths[i]);
		i++;
	}
	if (parse->tab)
	{
		i = 0;
		while (i < parse->m_h)
		{
			if (parse->tab[i])
				free(parse->tab[i]);
			i++;
		}
		free(parse->tab);
	}
	ft_lstclear(&parse->lines, &free);
}
