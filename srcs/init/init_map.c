/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:10:37 by noam              #+#    #+#             */
/*   Updated: 2025/03/14 16:11:14 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub.h>

void	init_map(t_map *map)
{
	map->grid = malloc(sizeof(int *) * 5);
	for (int i = 0; i < 5; i++)
	{
		map->grid[i] = malloc(sizeof(int) * 5);
	}
	int map_test[5][5] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 1, 1},
		{1, 1, 1, 1, 1}
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			map->grid[y][x] = map_test[y][x];
		}
	}

	map->tilesize = (WIDTH /2) /5;  // Make tiles visible
	map->mapx = 5;
	map->mapy = 5;
}
