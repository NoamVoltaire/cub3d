/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:10:37 by noam              #+#    #+#             */
/*   Updated: 2025/04/22 16:16:51 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_map(t_map *map, t_parse *parse)
{
	map->grid = parse->tab;
	map->mapx = parse->m_w;
	map->mapy = parse->m_h;
	map->tilesize = TILE_SIZE;
}
