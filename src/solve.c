/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarden <alcarden@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:44:42 by alcarden          #+#    #+#             */
/*   Updated: 2023/12/20 15:10:42 by alcarden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//Flood fill algorithm

int	ft_check_if_reachable(t_element element, int y, int x, int *value)
{
	char	**map_cpy;

	map_cpy = ft_cpy_map(element, element.map->full_map);
	if (map_cpy[x][y] != '1' && map_cpy[x][y] != 'T')
	{
		if (map_cpy[x][y] == 'E')
			*value = 1;
		if (map_cpy[x][y] == 'C')
			element.chest_counter++;
		element.map->full_map[y][x] = 'T';
		if (x + 1 < element.map->width)
			ft_check_if_reachable(element, x + 1, y, value);
		if (x - 1 >= 0)
			ft_check_if_reachable(element, x - 1, y, value);
		if (y + 1 < element.map->height)
			ft_check_if_reachable(element, x, y + 1, value);
		if (y - 1 >= 0)
			ft_check_if_reachable(element, x, y - 1, value);
	}
	return (*value);
}

char	**ft_cpy_map(t_element element, char **map)
{
	int		i;
	int		j;
	char	**map_cpy;

	i = 0;
	map_cpy = malloc(sizeof(char *) * element.map->height + 1);
	while (i < element.map->height)
	{
		map_cpy[i] = malloc(sizeof(char) * element.map->width + 1);
		j = 0;
		while (j < element.map->width)
		{
			map_cpy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (map_cpy);
}
